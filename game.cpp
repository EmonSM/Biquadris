#include "game.h"
#include "window.h"


// Modifies valid partial input to commmands understood by the program
// Ex. "ri" -> "right"
void game::getChangedInput(string& cmd) {

	int count = 0;
	string command;
	for (string i : com.listOfCom) {
		if (i.find(cmd) == 0) {
			command = i;
			count += 1;
		}
	}
	if (count == 1) {
		cmd = command;
	}
}

bool game::processInputs(string& cmd, ofstream& myfile, ifstream& inFile) {

	int count;
	stringstream ss{ cmd };
	ss >> count;
	ss >> cmd;
	getChangedInput(cmd);
	if (ss.fail()) {
		return false;
	}

	// open a file to store inputs if multiple are required to be done at one (Ex. "3right")
	myfile.open("tempFile.txt", std::ofstream::out | std::ofstream::trunc); // flags clears file everytime it is opened


	for (int i = 1; i < count; i += 1) {
		myfile << cmd;
		myfile << endl;
	}
	myfile.close();

	inFile.open("tempFile.txt");
	return true;
}

void game::runGame(int argc, char* argv[]) {

	vector <string> playersA;
	string argument;
	int startLevel = 0;
	int seed = 0;
	bool enableGraphics = true;

	playersA.emplace_back("sequence1.txt");
	playersA.emplace_back("sequence2.txt");

	for (int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
		ss >> argument;

		if (argument.substr(0, 11) == "-scriptfile") {
			if (argument.back() == '1') {
				playersA[0] = argv[i + 1];
				i += 1;
			}
			else if (argument.back() == '2') {
				playersA[1] = argv[i + 1];
				i += 1;
			}
			else {
				cout << argument.back() << endl;
				playersA.emplace_back(argv[i + 1]);
				i += 1;
			}
		}

		else if (argument == "-startlevel") {
			string aLevel(argv[i + 1]);
			stringstream theLevel(aLevel);
			theLevel >> startLevel;
			i += 1;
		}

		else if (argument == "-text") {
			enableGraphics = false;
		}

		else if (argument == "-seed") {
			string aSeed(argv[i + 1]);
			stringstream theSeed(aSeed);
			theSeed >> seed;
			i += 1;
		}
	}

	string cmd;
	int intCmd;
	TextDisplay d;

	ifstream inFile;
	ofstream myfile;

	int highScore;

begin:

	inFile.open("score.txt");
	if (inFile.is_open()) {
		inFile >> highScore;
		inFile.close();
	}
	else {
		highScore = 0;
	}

	bool fromFile = false;
	bool done = false;
	bool dropped = false;
	bool restartt = false;


	for (string s : playersA) {
		players.emplace_back(new Board(s, enableGraphics));
		players.back()->changeLevel(startLevel);
		players.back()->getCurrentLevel()->setSeed(seed);
	}

	d.printBoard(players, highScore);
	std::cout << endl;

	while (true) {

		for (Board* b : players) {

			dropped = false;

		start:

			if (!fromFile) {
				cout << "Player " << b->playerNumber << "'s turn. Enter command:" << endl;
				cin >> cmd;
				cout << endl;
				fromFile = processInputs(cmd, myfile, inFile);
			}

			if (fromFile) {
				inFile >> cmd;
				if (inFile.fail()) {
					inFile.clear();
					inFile.close();
					fromFile = false;
				}
			}


			if (cmd == com.right) {
				b->incrementGapLeft();
			}


			else if (cmd == com.left) {
				b->incrementGapLeft(-1);
			}

			else if (cmd == com.down) {
				if (!b->forceToPlace()) {
					b->incrementGapTop();
				}
				else {
					dropped = true;
				}

			}

			else if (cmd == com.drop) {
				b->drop();
				dropped = true;
			}

			else if (cmd == com.clockwise) {
				b->getCurrentBlock()->rotate(1);
				b->fixGap();
				if (b->getCurrentLevel()->heavy) {
					if (!b->forceToPlace()) {
						b->incrementGapTop();
					}
				}
			}

			else if (cmd == com.counterClockwise) {
				b->getCurrentBlock()->rotate(-1);
				b->fixGap();
				if (b->getCurrentLevel()->heavy) {
					if (!b->forceToPlace()) {
						b->incrementGapTop();
					}
				}
			}

			else if (cmd == com.heavy) {

				if (players.size() == 2) {
					if (players[0] == b) {
						players[1]->toggleHeavy();
					}
					else {
						players[0]->toggleHeavy();
					}
				}
				else if (cin >> intCmd && !cin.fail()) {
					if (intCmd <= players.size() && intCmd > 0) {
						players[intCmd - 1]->toggleHeavy();
					}
				}
				else if (cin.fail()) {
					cin.clear();
					cin >> cmd;
					goto fail;
				}
			}

			else if (cmd == com.blind) {

				if (players.size() == 2) {
					if (players[0] == b) {
						players[1]->toggleBlind();
					}
					else {
						players[0]->toggleBlind();
					}
				}
				else if (cin >> intCmd && !cin.fail()) {
					if (intCmd <= players.size() && intCmd > 0) {
						players[intCmd - 1]->toggleBlind();
					}
				}
				else if (cin.fail()) {
					cin.clear();
					cin >> cmd;
					goto fail;
				}
			}

			else if (cmd == com.force) {

				if (cin >> cmd) {

					int toChange = -1;
					if (players.size() == 2) {
						if (players[0] == b) {
							toChange = 1;
						}
						else {
							toChange = 0;
						}
					}

					else if (cin >> intCmd) {
						if (!cin.fail() && (intCmd <= players.size() && intCmd > 0)) {
							toChange = intCmd - 1;
						}
						else {
							cin.clear();
							cin >> cmd;
							goto fail;
						}
					}
					else {
						cin.clear();
						cin >> cmd;
						goto fail;
					}

					if (toChange != -1) {
						if (!players[toChange]->setCurrentBlock(cmd, players[toChange]->getCurrentBlock())) {
							goto fail;
						}
					}
				}
			}

			else if (cmd == com.levelUp) {
				b->changeLevel(1);
			}

			else if (cmd == com.levelDown) {
				b->changeLevel(-1);
			}

			else if (cmd == com.restart) {
				done = true;
				restartt = true;
				goto end;
			}

			else if (cmd == "L") {
				b->setCurrentBlock("L", b->getCurrentBlock());
			}
			else if (cmd == "T") {
				b->setCurrentBlock("T", b->getCurrentBlock());
			}
			else if (cmd == "S") {
				b->setCurrentBlock("S", b->getCurrentBlock());
			}
			else if (cmd == "Z") {
				b->setCurrentBlock("Z", b->getCurrentBlock());
			}
			else if (cmd == "I") {
				b->setCurrentBlock("I", b->getCurrentBlock());
			}
			else if (cmd == "O") {
				b->setCurrentBlock("O", b->getCurrentBlock());
			}
			else if (cmd == "J") {
				b->setCurrentBlock("J", b->getCurrentBlock());
			}

			else if (cmd == com.sequence) {
				cin >> cmd;
				inFile.open(cmd);
				fromFile = true;
			}


			else if (cmd == com.exit) {
				done = true;
				break;
			}

			else {

			fail:
				cout << endl;
				cout << "Invalid Input" << endl;
				cout << "Please try again" << endl;
				cout << endl;
				goto start;
			}

			if (b->specialAction) {
				bool failed = true;
				while (failed) {
					cout << "Enter a special action:" << endl;
					failed = false;
					cin >> cmd;

					getChangedInput(cmd);
					if (cmd == com.heavy) {

						if (players.size() == 2) {
							if (players[0] == b) {
								players[1]->toggleHeavy();
							}
							else {
								players[0]->toggleHeavy();
							}
						}
						else if (cin >> intCmd && !cin.fail()) {
							if (intCmd <= players.size() && intCmd > 0) {
								players[intCmd - 1]->toggleHeavy();
							}
						}
						else if (cin.fail()) {
							cin.clear();
							cin >> cmd;
							failed = true;
						}
					}

					else if (cmd == com.blind) {

						if (players.size() == 2) {
							if (players[0] == b) {
								players[1]->toggleBlind();
							}
							else {
								players[0]->toggleBlind();
							}
						}
						else if (cin >> intCmd && !cin.fail()) {
							if (intCmd <= players.size() && intCmd > 0) {
								players[intCmd - 1]->toggleBlind();
							}
						}
						else if (cin.fail()) {
							cin.clear();
							cin >> cmd;
							failed = true;
						}
					}

					else if (cmd == com.force) {

						if (cin >> cmd) {

							int toChange = -1;
							if (players.size() == 2) {
								if (players[0] == b) {
									toChange = 1;
								}
								else {
									toChange = 0;
								}
							}

							else if (cin >> intCmd) {
								if (!cin.fail() && (intCmd <= players.size() && intCmd > 0)) {
									toChange = intCmd - 1;
								}
								else {
									cin.clear();
									cin >> cmd;
									failed = true;
								}
							}
							else {
								cin.clear();
								cin >> cmd;
								failed = true;
							}

							if (toChange != -1) {
								if (!players[toChange]->setCurrentBlock(cmd, players[toChange]->getCurrentBlock())) {
									failed = true;
								}
							}
						}
					}
					else {
						failed = true;
					}

					if (failed) {
						cout << endl;
						cout << "Invalid Input" << endl;
						cout << "Please try again" << endl;
						cout << endl;
					}
				}
				b->specialAction = false;

			}

			if (b->getScore() > highScore) {
				highScore = b->getScore();
			}

			if (b->checkEnd()) {
				cout << "Player " << b->playerNumber << " wins with a final score of " << b->getScore() << endl;
				cout << "Game Over" << endl;

				done = true;
				goto end;
			}

			if (!fromFile) {
				d.printBoard(players, highScore);

				cout << endl;
			}

			if (enableGraphics) {
				b->outputGraphics();
			}

			if (!dropped) {
				goto start;
			}
		}

	end:

		if (done) {
			myfile.open("score.txt", std::ofstream::out | std::ofstream::trunc);
			myfile << highScore;
			myfile.close();


			for (Board* b : players) {
				delete b;
			}
			while (players.size() != 0) {
				players.pop_back();
			}
			if (restartt) {
				goto begin;
			}
			break;
		}
	}
}
