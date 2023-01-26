#include <iostream>
// Libraries for rand()
#include <cstdlib>
#include <ctime>

using namespace std;

// Greets the Player and passes the user's name by reference
void greeting(string &name){
    cout << "Welcome to bowling!" << endl;
    cout << "What's your name? ";
    cin >> name;

    cout << "Hello " << name << "!" << endl;
    cin.ignore();
}

// This function populates the arrays used in the program.  A int value of -1 indicates that the program has not reached this stage in the program yet, and it is an "open frame"
void populate_arrays(int rollScore[], int totalScore[], int frameState[]){
    for(int i = 0; i < 21; i++){
        rollScore[i] = -1;
    }
    
    for(int i = 0; i < 11; i++){
        totalScore[i] = -1;
        frameState[i] = -1;
    }
    
}


void create_linesFirst(int &x){
    if(x % 2 == 0 && x != 20){
        cout << "| ";
    }
    // else{
    //     cout << " ";
    // }
}

// After the number has been printed on the scoreboard
void create_linesSecond(int &x){
    if(x % 2 == 1){
        cout << "";
    }
    else if(x == 20){
        cout << "|";
    }
}

void print_gutter_scoreboard(int &x){
    if((x % 2 == 0) && (x != 20)){
        cout << "-  ";
    }
    else if(x == 20){
        cout << " -";
    }
    else{
        cout << "-";
    }
}

// Printing an X for a strike on the scoreboard
void print_strike_scoreboard(int &x){
    if(x == 0){
        //cout << "| X  ";
        cout << "X  ";    
    }
    else{
        cout << "X  ";    
    }
}

// Prints the special cases for the scoreboard (strike, spare, gutter, and general case)
void print_special_cases(int rollScore[], int &x, int frameState[], int &frame, int &currentRoll){
    create_linesFirst(x);
    
    if((rollScore[x] == 10 && rollScore[x - 1] == 0) && ((x % 2 == 1) && ((x-1) % 2 == 0))){
        cout << "/";
    }
    else if(rollScore[x] == 10){
        print_strike_scoreboard(x);
    }
    
    else if((((rollScore[x] + rollScore[x-1]) == 10) && ((x - 1) == 0)) || (((rollScore[x] != 0) && ((rollScore[x] + rollScore[x-1]) == 10)) && ((x % 2 == 1) && ((x-1) % 2 == 0)))){
        cout << "/";
    }
    
    // // Unique case where the spare is in the first frame
    // else if(((rollScore[x] + rollScore[x-1]) == 10) && ((x - 1) == 0)){
    //     cout << "/";
    // }

    else if(rollScore[x] == 0){
        print_gutter_scoreboard(x);
    }
    else{
        if(x % 2 == 0 && (x != 20)){
            //cout << "| " << rollScore[x] << "  ";
            cout << rollScore[x] << "  ";
        }
        else{
            cout << rollScore[x];
        }
    }
    create_linesSecond(x);
}

void special_sum_cases(int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    for(int j = 0; j < 21; j+2){
        // If the rollScore at that frame is NOT a strike
        if(rollScore[j] || rollScore[j+1] != 10){
           // totalScore[i]
        }
        // else if(){

        // }

    }
}

// This function will add the roll scores together in each frame, and will store to totalScores array
void sum_roll_scores(int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    // Do not sum if the frame is still open (0)
    if(frameState[frame] == 0){
        cout << "frame is still open" << endl;
    }
    // Sum the roll scores if the frame is CLOSED (1) --> Ready for sum
    else if(frameState[frame] == 1){
        for(int i = 0; i < 10; i++){
            if(currentRoll % 2 == 0 && currentRoll != 22){
                for(int y = 0; y < 21; y++){
                    totalScore[i] = (rollScore[y] + rollScore[y - 1]);
                }
                cout << "first roll adding with second roll: ";
                
            }
            // else if(currentRoll % 2 == 1){
                
            //     cout << "second roll adding with "
                
                
            //     totalScore[i] = rollScore[currentRoll] + rollScore[currentRoll ];
            // }
            
        }
    }
    // Strike case -- sum the next TWO rolls
    // Frame state of 2 means that the user scored a strike in this frame for the FIRST roll   
    // else if(frameState[frame] == 2){
    //     if(rollScore[currentRoll] != -1 && (rollScore[currentRoll + 2] != -1) && (rollScore[currentRoll + 4] != -1)){

    //     }
    // }

    for(int i = 0; i < 10; i++){
        if(totalScore[i] == -1){
            
        }
        else{
            //special_sum_cases(rollScore, totalScore, frame, currentRoll, frameState, i);
        }
    }

}

// Shifts the roll and frame for the sum_each_frame() function
void shift_roll_and_frame(int &checkFrame, int &firstRoll, int &secondRoll, int &thirdRoll){
    if(firstRoll == 19 && secondRoll == 20 && thirdRoll == 21){
        // make sure values are no longer in scope of the while loop in total_scores_scoreboard()
        
        checkFrame++;
        firstRoll += 2;
        secondRoll += 2;
        thirdRoll += 5;
    }
    else{
        checkFrame++;
        firstRoll += 2;
        secondRoll += 2;
    }
}

void strike_sum_frame(int &x, int rollScore[], int totalScore[], int &checkFrame, int &firstRoll, int &secondRoll, int &thirdRoll){
    // User gets a second strike in a row
    if(rollScore[x + 2] == 10 && (x + 2 < 21)){
        // User gets a third strike in a row
        if(rollScore[x + 4] == 10 && (x + 4 < 21)){
            totalScore[x/2] = rollScore[x] + rollScore[x + 2] + rollScore[x + 4];
        }
            
        // Only add up the two strikes and the next roll
        else{
            totalScore[x/2] = rollScore[x] + rollScore[x + 2] + rollScore[x + 3];
        }
    }
    else{
        // In the case that the user gets a strike on the last roll
        if(firstRoll == 21){
            totalScore[x/2] = rollScore[x - 1] + rollScore[x - 2];
        }
            
    }
}

void spare_sum_frame(int &x, int rollScore[], int totalScore[], int &checkFrame, int &firstRoll, int &secondRoll, int &thirdRoll){
    // Spare in Second Roll 
        // DOES NOT MATTER?????????
    // if(rollScore[firstRoll] == 0 && rollScore[secondRoll] == 10){
    //     totalScore[checkFrame] = rollScore[firstRoll]         
    // }

    // 10th Frame, in the case of a Third Roll
    // if(firstRoll == 19 && checkFrame == 9){
    //     totalScore[checkFrame] = rollScore[firstRoll] + rollScore[secondRoll] + rollScore[thirdRoll];
    // }
    
    // General Spare Case
    totalScore[x/2] = rollScore[x] + rollScore[x+1] + rollScore[x + 2];
    

}

void sum_each_frame(int &x, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[], int &checkFrame, int &firstRoll, int &secondRoll, int &thirdRoll){
    // // General Case
    // if((rollScore[firstRoll] != -1 && rollScore[secondRoll] != -1) && rollScore[firstRoll] != 10 && (rollScore[secondRoll] != 10) && (rollScore[firstRoll] + rollScore[secondRoll] != 10)){
    //     totalScore[checkFrame] = rollScore[firstRoll] + rollScore[secondRoll];
        
        
    //     shift_roll_and_frame(checkFrame, firstRoll, secondRoll, thirdRoll);
    // }

    // General Case FIXED WITH LOOP
    

    if((rollScore[x] != 10 && rollScore[x+1] != 10) && (rollScore[x] != -1 && rollScore[x+1] != -1) && ((rollScore[x] + rollScore[x+1] != 10))){
        // Divides the EVEN roll number by two, so we obtain the frame number
        totalScore[x/2] = rollScore[x] + rollScore[x+1];
    }

    // Strike    --> else if()
    else if(rollScore[x] == 10){
        strike_sum_frame(x, rollScore, totalScore, checkFrame, firstRoll, secondRoll, thirdRoll);

        // // User gets a second strike in a row
        // if(rollScore[firstRoll + 2] == 10 && (firstRoll + 2 < 21)){
        //     // User gets a third strike in a row
        //     if(rollScore[firstRoll + 4] == 10 && (firstRoll + 4 < 21)){
        //         totalScore[checkFrame] = rollScore[firstRoll] + rollScore[firstRoll + 2] + rollScore[firstRoll + 4];
        //     }
            
        //     // Only add up the two strikes and the next roll
        //     else{
        //         totalScore[checkFrame] = rollScore[firstRoll] + rollScore[firstRoll + 2];
        //     }
        // }
        // else{
        //     // In the case that the user gets a strike on the last roll
        //     if(firstRoll == 21){
        //         totalScore[checkFrame] = rollScore[firstRoll];
        //     }
            
        // }
    }
    // Spare
    else if(rollScore[x] + rollScore[x+1] == 10){
        spare_sum_frame(x, rollScore, totalScore, checkFrame, firstRoll, secondRoll, thirdRoll);
    }
    // increment so we can get total score somehow?
    else{
        
    }

    
}

// Function that prints out the total scores on the scoreboard
void total_scores_scoreboard(int &x, string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    cout << "" << endl; // get out of the roll score line
    cout << "            |"; // second line of scores
    
    int checkFrame = 0; 
    int firstRoll = 0; 
    int secondRoll = 1; 
    int thirdRoll = 20;
    // while((checkFrame) < 11 && (firstRoll < 21) && (secondRoll < 21) && (thirdRoll < 21)){
    sum_each_frame(x, rollScore, totalScore, frame, currentRoll, frameState, checkFrame, firstRoll, secondRoll, thirdRoll);
    //     // cout << "test" << endl;
    //     // break;
    // }
    if(rollScore[currentRoll] == -1){
        checkFrame++;
        // firstRoll += 1;
        // secondRoll += 1;
    }
    else{
        if(rollScore[currentRoll != -1]){
            sum_each_frame(x, rollScore, totalScore, frame, currentRoll, frameState, checkFrame, firstRoll, secondRoll, thirdRoll);
        }
    }
    
    // // Adding the values together
    // for(int h = 0; h < 10; h++){
    //     //sum_roll_scores(rollScore, totalScore, frame, currentRoll, frameState);

    //     if(frameState[h] == 0){
    //     cout << "frame is still open" << endl;
    //     }
    //     // Sum the roll scores if the frame is CLOSED (1) --> Ready for sum
    //     else if(frameState[h] == 1){
    //         for(int i = 0; i < 10; i++){
    //             totalScore[h] = (rollScore[] + rollScore[y - 1]);
                
    //             cout << "first roll adding with second roll: ";
                    
    //             }
    //             // else if(currentRoll % 2 == 1){
                    
    //             //     cout << "second roll adding with "
                    
                    
    //             //     totalScore[i] = rollScore[currentRoll] + rollScore[currentRoll ];
    //             // }
                
    //         }
    //     }
        
        

    // Printing out the values
    // for(int i = 0; i < 10; i++){
    //     if(totalScore[i] == -1){
    //         // Do not print anything when the totalScore equals -1
    //     }
    //     else{
    //         // cout << "frame " << i << " state: " << frameState[i] << " | ";
    //         cout << totalScore[i] << "   |";
    //     }
    // }
    

    
    cout << "" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}

void numSpaces(string name){
    if(name.length() < 12){
        int numSpaces = name.length();
        while(numSpaces < 12){
            cout << " ";
            numSpaces++;
        }
    }
}

// This function will print out the TOTAL scores in the scoreboard
void printTotalScores(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    // Printing out the values
    for(int i = 0; i < 10; i++){
        if(totalScore[i] == -1){
            // Do not print anything when the totalScore equals -1
        }
        else{
            // cout << "frame " << i << " state: " << frameState[i] << " | ";
            cout << totalScore[i] << "   |";
        }
    }
}

// Prints out the scoreboard after every roll -- contains the styling
// Will most likely need parameters that have the scores
void scoreboard(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    cout << "Name        |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |Total" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << name;
    
    // Adds spaces after the name so the scoreboard is lined up
    numSpaces(name);


    for(int x = 0; x < 21; x++){
        if(rollScore[x] == -1 || ((rollScore[x - 1] == 10 || (rollScore[x - 1] + rollScore[x - 2] == 10)) && x == 21)){
            cout << " ";
        }
        else{
            print_special_cases(rollScore, x, frameState, frame, currentRoll);
            printTotalScores(name, rollScore, totalScore, frame, currentRoll, frameState);
            
            if((x+1) % 2 == 0){
                // Conditional so a line isn't placed in final frame when there is Roll Three
                if(frame == 9 && currentRoll == 20){
                    cout << "";
                }
                else if(rollScore[x] == 10 && (x % 2 == 0)){
                    cout << "| ";
                }
                
            }

            // If statement makes sure that x is an even number, OR it is 0. Won't run otherwise
            // if(((x % 2 == 0) && x != 20) || x == 0){
            //     // Print out the total score portion of the scoreboard
            //     total_scores_scoreboard(x, name, rollScore, totalScore, frame, currentRoll, frameState);
            // }
            

        }
    }

    //total_scores_scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
    cout << "" << endl; // second line of scores
    cout << "-----------------------------------------------------------------------------" << endl;
    

}

void frame_ten_one(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if(frame == 9 && currentRoll == 18){
        cout << "Frame 10..." << endl;

        cout << "Press enter to roll." << endl;
        cin.ignore();

        int randomNum = rand() % 11;
        rollScore[18] = randomNum;

        if(rollScore[18] == 10){
            cout << "You got a strike, 10 pins." << endl;
        }
        else if(rollScore[18] == 0){
            cout << "Awe, you got a gutter ball, 0 pins." << endl;
        }
        else{
            cout << "You knocked down " << rollScore[18] << " pins." << endl;
        }
        scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
        // function call for total score

        currentRoll = 19;
    }
}

// Shortens frame_ten_two() by calling a function to print out its unique messages
void frame_ten_extra_output(int rollScore[], int i){
    if(rollScore[i] == 10){
        cout << "You got a strike, 10 pins." << endl;
    }
    else if(rollScore[i] == 0){
        cout << "Awe, you got a gutter ball, 0 pins." << endl;
    }
    else{
        cout << "You knocked down " << rollScore[i] << " pins." << endl;
    }
}

void frame_ten_two(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if(frame == 9 && currentRoll == 19){
        cout << "Press enter to roll." << endl;
        cin.ignore();

        
        if(rollScore[18] == 10){
            rollScore[19] = rand() % 11;
            frame_ten_extra_output(rollScore, 19);
        }
        else if(rollScore[18] != 0){
            rollScore[19] = rand() % (11 - rollScore[18]);

            frame_ten_extra_output(rollScore, 19);
        }
        else{
            rollScore[19] = rand() % 11;
            frame_ten_extra_output(rollScore, 19);
        }
            
        // Function that will make sure spares do not calculate from rolls OUT OF THE CURRENT FRAME
        //rollTwo_special_cases(name, rollScore, totalScore, frame, currentRoll, frameState);
            
        //uniqueMessages(rollScore, frameState, frame, currentRoll);
        scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
        currentRoll = 20;
    }
}

void frame_ten_three(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if(frame == 9 && currentRoll == 20 && (((rollScore[18] + rollScore[19] == 10) || (rollScore[19] == 10) || (rollScore[18] == 10)))){
        cout << "Press enter to roll." << endl;
        cin.ignore();

        if(rollScore[19] == 10){
            rollScore[20] = rand() % 11;
            frame_ten_extra_output(rollScore, 20);
        }
        else if(rollScore[19] != 0){
            rollScore[20] = rand() % (11 - rollScore[19]);

            frame_ten_extra_output(rollScore, 20);
        }
        else{
            rollScore[19] = rand() % 11;
            frame_ten_extra_output(rollScore, 20);
        }

        scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);

    }
    // If the conditional above is not true, then the user did not EARN a third roll. Exit the while loop.
    currentRoll = 21; // while loop in main() is now no longer true
}

void rollThree_special_cases(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]);

// Put above rollOne() function so rollOne can call it
void rollThree(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]);

void rollOne_message_output(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    // Strike case
    if((rollScore[currentRoll] == 10)){     
        cout << "You got a strike, 10 pins." << endl;
        
    }

    // Gutter Ball
    else if(rollScore[currentRoll] == 0){
        cout << "Awe, you got a gutter ball, 0 pins." << endl;
    }

    // General case with print statement
    else{
        cout << "You knocked down " << rollScore[currentRoll] << " pins." << endl;
    }   
}


// Will sum the total scores in Roll One (SPECIAL CASES, like multiple strikes in a row)
void sum_roll_one_scores(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if(currentRoll % 2 == 0){
        // Three strikes in a row
        if((currentRoll != 20) && (frameState[frame - 2] == 2 && (rollScore[currentRoll-2] == 10) && (rollScore[currentRoll-4] == 10))){
        
        // Do in increments of 2 for the currentRoll, since every frame is 2 rolls (indices)
        totalScore[frame - 2] = rollScore[currentRoll - 4] + rollScore[currentRoll - 2];
        
        // Close that frame for scoring
        frameState[frame - 2] = 1;
        }
    }
    
    // // Normal Strike Case
    // else if(frameState[frame - 2] == 2 && (rollScore[currentRoll - 1] != 10)){
    //     totalScore[frame - 2] = rollScore[currentRoll - ]
    // }
    

    // Strike
    


}

void sum_roll_two_scores(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
     

}

// Special cases for rollOne
void rollOne_special_cases(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if((rollScore[currentRoll] == 10)){     // % 2 == 1 means for the FIRST roll of EACH frame
                
        rollScore[currentRoll + 1] = -1;
        if(frame < 9){
            currentRoll = currentRoll + 2;
            frame++;

        }

        frameState[frame - 1] = 2;  // Still allowed for scoring, since a strike takes NEXT two rolls for score
        
    }

    // Gutter Ball
    else if(rollScore[currentRoll] == 0){
        currentRoll++;
    }

    // General case with print statement
    else{
        currentRoll++;
    }   
            

}

void rollOne(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
        if(frame == 9 && currentRoll >= 18){
            frame_ten_one(name, rollScore, totalScore, frame, currentRoll, frameState);
            frame_ten_two(name, rollScore, totalScore, frame, currentRoll, frameState);
            frame_ten_three(name, rollScore, totalScore, frame, currentRoll, frameState);
        }
        else{
            frameState[frame] = 0;
            cout << "Frame " << frame + 1 << "..." << endl;      // Fix this
            cout << "Press enter to roll." << endl;
            cin.ignore();

            int randomNum = rand() % 11;   // Modulus 11 so the limit is 0-10
            
            rollScore[currentRoll] = randomNum;  // Save the number to the array FIRST, so you can use the array in the unique messages function (for SPARES)

            rollOne_message_output(name, rollScore, totalScore, frame, currentRoll, frameState);
            
            //uniqueMessages(rollScore, frameState, frame, currentRoll);
            scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
            rollOne_special_cases(name, rollScore, totalScore, frame, currentRoll, frameState);

            //sum_roll_one_scores();
        }

    
}

void rollTwo_special_cases(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    // a spare (roll one and two == 10)
    if(((rollScore[currentRoll] != 0) && ((rollScore[currentRoll] + rollScore[currentRoll - 1] == 10) && (currentRoll % 2 == 1)))){
        
        // Print unique message for spares (either singular pin or multiple pins)
        if(rollScore[currentRoll] == 1){
            cout << "You knocked down " << rollScore[currentRoll] << " pin, Spare!" << endl;
        }
        else{
            cout << "You knocked down " << rollScore[currentRoll] << " pins, Spare!" << endl;
        }

        // Frame state of 3 means that the user scored a spare in this frame
        frameState[frame] = 3;
    }
    // Strike case
    // else if(rollScore[currentRoll] == 10){
    //     cout << "You got a strike, 10 pins." << endl;
    // }
    
    // Gutter Ball
    else if(rollScore[currentRoll] == 0){
        cout << "Awe, you got a gutter ball, 0 pins." << endl;
        frameState[frame] = 1;  // Close the frame, since we are in the second roll
        /* We want to close the frame BEFORE calling scoreboard() in rollTwo(),
        *  that way scoreboard() --> total_scores_scoreboard() --> sum_roll_scores().
        */
    }

    // General case with general print statement
    else{
        cout << "You knocked down " << rollScore[currentRoll] << " pins." << endl;
        frameState[frame] = 1;  // close the frame for scoring
    } 
     
}



void rollTwo(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){            
    // if(frame == 9){
    //     frame_ten_two(name, rollScore, totalScore, frame, currentRoll, frameState);
    // }

    if((((rollScore[currentRoll - 2] == 10 && rollScore[currentRoll - 3] == 0) || (rollScore[currentRoll - 2] != 10)) && frame != 9)){
        cout << "" << endl;
        cout << "Press enter to roll." << endl;
        cin.ignore();

        int randomNum = rand() % (11 - rollScore[currentRoll - 1]);   // Modulus 11 so the limit is 0-10
                
        rollScore[currentRoll] = randomNum;
        
        // Function that will make sure spares do not calculate from rolls OUT OF THE CURRENT FRAME
        rollTwo_special_cases(name, rollScore, totalScore, frame, currentRoll, frameState);
        
        //uniqueMessages(rollScore, frameState, frame, currentRoll);
        scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
        
        // Run this if statement every time, unless the frame is 10
        if(frame != 9){
            //totalScore[frame] = rollScore[currentRoll - 1] + rollScore[currentRoll];            
            //frameState[frame] = 1;
            
            
            
            
            // sum_roll_scores(rollScore, totalScore, frame, currentRoll, frameState);




            currentRoll++;
            frame++;
        }
        
        // This else if statement happens if the user gets a strike or a spare in the 10th frame, they will get a THIRD roll.
        // else if(frame == 9){
        //     if((rollScore[currentRoll] == 10) || (rollScore[currentRoll] + rollScore[currentRoll - 1] == 10)){
        //         currentRoll++;
        //         rollThree(name, rollScore, totalScore, frame, currentRoll, frameState);
        //     }
        //     else{
        //         currentRoll = 30;
        //     }
        // }
    }
    

    
}

void rollThree_special_cases(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    if((rollScore[currentRoll] == 10)){     // % 2 == 1 means for the FIRST roll of EACH frame
        
        cout << "You got a strike, 10 pins." << endl;
        
        rollScore[currentRoll + 1] = -1;        
    }
    
    // Gutter Ball
    else if(rollScore[currentRoll] == 0){
        cout << "Awe, you got a gutter ball, 0 pins." << endl;
    }

    // General case with print statement
    else{
        
        cout << "You knocked down " << rollScore[currentRoll] << " pins." << endl;
    }  
}

// Only for the last frame (10), and only if the user gets a strike.
void rollThree(string name, int rollScore[], int totalScore[], int &frame, int &currentRoll, int frameState[]){
    cout << "You get one final roll for this frame..." << endl;
    

    cout << "Press enter to roll." << endl;
    cin.ignore();

    if(rollScore[currentRoll - 1] == 10){
        int randomNum = rand() % 11;
        rollScore[currentRoll] = randomNum;
    }
    else{
        int randomNum = rand() % (11 - rollScore[currentRoll - 1]);
        rollScore[currentRoll] = randomNum;
    }
    
    rollThree_special_cases(name, rollScore, totalScore, frame, currentRoll, frameState);
    scoreboard(name, rollScore, totalScore, frame, currentRoll, frameState);
    currentRoll++;
    frame++;
    
}

// void scoring(int rollScore[]; int totalScore[]; int &frame){

//     for(int i = 0; i < size)
//     rollOne();
//     rollTwo();
//     if(i ){     // rollThree function exception

//     }
// }



int main(){
    /* Initialize Random Seed */
	srand(time(NULL));
    
    int frame = 0;  // Will increment frame after every second roll, except when it gets to frame 10
    int currentRoll = 0;

    int rollScore[21];
    int totalScore[11];
    int frameState[10];     // 0 for open frame, 1 for spare, 2 for strike? -- CHECK SLIDES
    

    populate_arrays(rollScore, totalScore, frameState);
    
    string playerOneName;
    greeting(playerOneName);    
    while((frame < 10) && (currentRoll < 21)){
        rollOne(playerOneName, rollScore, totalScore, frame, currentRoll, frameState);
        rollTwo(playerOneName, rollScore, totalScore, frame, currentRoll, frameState);
        
    }


    return 0;
}
