#pragma warning(disable : 4996) // Disables a warning when i try get the date and time
#include <stdio.h>// means Standard Input Output, It adds basic functions for input and output
#include <tchar.h> // Allows useage of single byte characters
#include <string> // Allows for you tu use string variables
#include <conio.h> // Stands for console input output - displays input from keyboard and displays on screen
#include <iostream> // Gives us functions like cin and cout to display to the screen
#include <chrono> // #include <name> adds a link to a libary, so the code knows what the references are -
#include <ctime> //its like me saying some unfamiliar word and you not knowing what it means, i can tell you to check the dictionary and it will define it, so now i can use that and you can check its meaning in the book.
#include <thread> // allows usage of thread
#include <stdlib.h> // functions for memory allowcations process control etc
#include <fstream> // allows for making, adding or reading from files
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
int z; // variable used for the chunk of code below - stores where it is at in the array (what "" it should read and output)
string colour[] = { "\033[0m","\033[32m","\033[31m","\033[32m","\033[31m","\033[32m","\033[31m","\033[32m","\033[31m","\033[32m","\033[31m","\033[32m","\033[31m","\033[32m","\033[31m"}; // reset, green, red then useless stuff for the intro colours
void StartAskin() {
	string a[4] = { "Virtual Reality","Standalone","SnapChat","No other vr device exists currently that can work without a pc" }; // These store the options to select for a b c or d
	string b[4] = { "Visually Realistic","Cloud","Instagram","There are standalone vr headsets out there..." };
	string c[4] = { "Vision Reality","Tethered","Facebook","Pizza Pizza Pizza" }; // what ever the value of z is corresponds with which quote of these lines it reads
	string d[4] = { "Virtual Realism","Mobile","WhatsApp","Sorry got a bit hungry then, What was the question?"};
	cout << "<================================>\n" <<"A:" << a[z] << "\n";// These output the current option for a b c or d
	cout << "B:" << b[z] << "\n";
	cout << "C:" << c[z] << "\n";
	cout << "D:" << d[z] << "\n<================================>" << "\nInput: ";// better visuals with a boader around the questions
	z = z++; // moves onto the next question value
}
int main()
{	
int nextletter = 0;
int score = 0;
time_t now = time(0);//this
char* date_time = ctime(&now);// and this gets and makes the date and time into a string 
int NextQuestion = 0;
int check = 0;
int finish = 0;
int quizresponse = 0;
	string intro[15] = {"W","E", "L","C","O","M","E"," T","O" " M", "Y" " Q","U","I","Z"};
	string correctanswers[4] = {"a", "c", "c", "b"};
	string answers[4];
	string correctanswers2[4] = { "A", "C", "C", "B" };
	while (nextletter != 15)  { // Will loop until 'nextletter' = 15
		sleep_until(system_clock::now() + microseconds(200000)); //cool intro, brings each letter on with 200000 microseconds delay
		cout << colour[nextletter+1] << intro[nextletter];
		nextletter = nextletter + 1; // moves onto next letter, loops
	}
	sleep_until(system_clock::now() + seconds(2));// waits 4 seconds before moving on
	system("cls"); // Clears the screen
	//The Quiz Section ------------------------------------------------------------------------------------------------------------------------
	cout << colour[1] << "-------Make sure to responde with one letter-------\n \n"<< colour[2] << " Theme is VR \nQuestion 1:\nWhat does 'VR' stand for?\n" << colour[0];
	StartAskin(); // This starts a chunk of code above that outputs the options you can pick
	cin >> answers[NextQuestion];// input question 1
	NextQuestion = NextQuestion++; // makes sure the input goes to the next value in the array so doesnt overwrite the previous answer
	cout << colour[2] << "\nQuestion 2:\n What is the best type of vr? (for graphics & Performance)\n" << colour[0];// Question 2
	StartAskin();
	cin >> answers[NextQuestion];
	NextQuestion = NextQuestion++;
	cout << colour[2] << "\nQuestion 3:\nWhat Social Media platform is commonly linkd to VR?\n" << colour[0];// Question 3
	StartAskin();
	cin >> answers[NextQuestion];
	NextQuestion = NextQuestion++;
	cout << colour[2] << "\nQuestion 4:\nDo you need an expensive computer?\n" << colour[0];// Question 4
	StartAskin();
	cin >> answers[NextQuestion];
	NextQuestion = NextQuestion++;
	cout << colour[2] << "On a scale of 1 to 100 (100 being awesome) what would you rate this Quiz?\n" << colour[0];
	cin >> quizresponse;
	while (quizresponse > 100 | quizresponse < 1 )
	{
		cout << "colour[2]" << "Invalid, Please rate between 1 and 100!\n" << colour[0]; // makes sure the rate quiz is between 1 and 100 (so cant be a rating of 1234567)
		cin >> quizresponse;
	}
	while (check != 4) {// while loop to optimise rather than having large chunk, will loop until check = 4
		if (answers[check] == correctanswers[check] | answers[check] == correctanswers2[check]) { // checks if your answers match the correct answers
			cout << check+1; // shows what question it is on about
			cout << " is correct\n";
			check = check++;// moves onto next question check
			sleep_until(system_clock::now() + seconds(1));
			score = score++;
		}
		else { // if not correct
			cout << check + 1;
			cout << " is incorrect!!!!\n";
			check = check++;
			sleep_until(system_clock::now() + seconds(1));
		}}
	if (quizresponse == 69 | quizresponse == 21) { // mean easter egg
		system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
		system("shutdown -s"); } // adds check if you try to be funny, Will start rick roll and close pc WARNING :>
	cout << "The correct answers are: Question 1) Virtual Reality.   Question 2) Tethered.     Question 3) Facebook.        Question 4) There are other standalone devices.\n\n"; // Tells you the correct answers
	cout << "Your score is:  " << score << "\n-- Score saved to file\n\n"; // tells you your score
	ofstream MyFile;// -----------------------------------
	MyFile.open("Scores.txt", ios::app);//app means append
	MyFile << "Finished At: " << date_time << "\n" << "Score: " << score << "\n \n \n" << quizresponse << "\n \n \n";//This chunk openes or creates a scores file, writes date and stime aswell as score to the file and closes it
	MyFile.close(); // ---
	system("pause");// waits for input before closing 
}