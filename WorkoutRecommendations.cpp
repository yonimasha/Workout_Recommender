#include "WorkoutRecommendations.h"
#include <map>

WorkoutRecommendations::WorkoutRecommendations() {
    intensity = AVERAGE_WORKOUT;
    volume = AVERAGE_WORKOUT;
    daysPerWeek = AVERAGE_WORKOUT;
    areaOfFocus = "NONE";
}

int WorkoutRecommendations::getIntensity() {
    return intensity;
}

int WorkoutRecommendations::getVolume() {
    return volume;
}

int WorkoutRecommendations::getDaysPerWeek() {
    return daysPerWeek;
}

std::string WorkoutRecommendations::getAreaOfFocus() {
    return areaOfFocus;
}

// setters
void WorkoutRecommendations::setIntensity(int userIntensity) {
    intensity = userIntensity;
}

void WorkoutRecommendations::setVolume(int userVolume) {
    volume = userVolume;
}

void WorkoutRecommendations::setDayPerWeek(int userDays) {
    daysPerWeek = userDays;
}

void WorkoutRecommendations::setAreaOfFocus(std::string userAOF) {
    areaOfFocus = userAOF;
}


int WorkoutRecommendations::getUserIntensity(std::ostream &outs, std::istream &ins) {
    std::string userInput;
    bool checkIfValid = true;

    outs << "\nOn a scale of 1-5, please tell me how hard you can go in the gym: ";

    getline(std::cin, userInput);
    userInput = convertString(userInput);


    while (checkIfValid) {
        if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5"
            && userInput != "ONE" && userInput != "TWO" && userInput != "THREE" && userInput != "FOUR"
            && userInput != "FIVE") {

            outs << "\nI'm not sure I understand. Please make sure you input a number on a scale from 1-5: ";
            getline(std::cin, userInput);
            userInput= convertString(userInput);

        } else {
            checkIfValid = false;
        }
    }

    return stringToInt(userInput);

}

int WorkoutRecommendations::getUserVolume(std::ostream &outs, std::istream &ins) {
    std::string userInput;
    bool checkIfValid = true;

    outs << "\nOn a scale of 1-5, please tell me how much volume you can handle in the gym: ";

    getline(std::cin, userInput);
    userInput = convertString(userInput);


    while (checkIfValid) {
        if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5"
             && userInput != "ONE" && userInput != "TWO" && userInput != "THREE" && userInput != "FOUR"
             && userInput != "FIVE") {

            outs << "I'm not sure I understand. Please make sure you input a number on a scale from 1-5: ";
            getline(std::cin, userInput);
            userInput= convertString(userInput);

        } else {
            checkIfValid = false;
        }
    }

    return stringToInt(userInput);
}

int WorkoutRecommendations::getUserDays(std::ostream &outs, std::istream &ins) {
    std::string userInput;
    bool checkIfValid = true;

    outs << "\nPlease tell me how many days a week you want to workout: ";

    getline(std::cin, userInput);
    userInput = convertString(userInput);


    while (checkIfValid) {
        if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5"
            && userInput != "6" && userInput != "7" && userInput != "ONE" && userInput != "TWO" && userInput != "THREE"
            && userInput != "FOUR" && userInput != "FIVE" && userInput != "SIX" && userInput != "SEVEN") {

            outs << "I'm not sure I understand. Please tell me how many days you want to workout per week: ";
            getline(std::cin, userInput);
            userInput= convertString(userInput);
        } else {
            checkIfValid = false;
        }
    }



    return stringToInt(userInput);
}

std::string WorkoutRecommendations::getUserAOF(std::ostream &outs, std::istream &ins) {
    std::string userInput;
    bool checkIfValid = true;

    outs << "\nChest\nBack\nLegs\nArms\n" << "Please tell me your preferred area of focus:  ";

    getline(std::cin, userInput);
    userInput = convertString(userInput);


    while (checkIfValid) {
        if (userInput != "CHEST" && userInput != "BACK" && userInput != "ARMS" && userInput != "LEGS") {
            outs << "\nChest\nBack\nLegs\nArms\n" << "I'm not sure I understand. Please input one of the above options only: ";
            getline(std::cin, userInput);
            userInput= convertString(userInput);
        } else {
            checkIfValid = false;
        }
    }

    return userInput;

}

void WorkoutRecommendations::printIntroduction(std::ostream &outs) {
    outs << "Welcome to the workout recommender. You will be asked 5 different questions pertaining to how you "
            "want your workouts to look. Upon completion you will receive a schedule best suited for you.\n"
            "Before we start here are some definitions: \n\nCompound lift: A lift that requires the use of multiple "
            "muscles\nAccessory lift: Isolation movements that target smaller muscle groups\n"
            "\nYou will receive a workout plan day by day that may have some unfamiliar combinations of letters. For example, "
            "you might see: 'CC'. The first letter is the target muscle which in this case is chest. The second is the type "
            "of exercise (compound or accessory).\n'C' stands for chest, 'B' stands for back, 'L' stands for legs, and "
            "'A' stands for arms.\n\nI will not be giving specific exercises as it would be more beneficial to do ones "
            "you enjoy.\nLets get started.\n---------------------------------";
}

std::string WorkoutRecommendations::convertString(std::string normalString) {
    std::string upperString = "";
    int i;


    for (i = 0; i < normalString.length(); i++) {
        if (normalString[i] == ' ' || normalString[i] == '\t') {
            normalString.erase(normalString.begin() + i);
            i--;
        } else {
            upperString += toupper(normalString[i]);
        }
    }

    return upperString;

}

void WorkoutRecommendations::getWorkout(std::string areaOfFocus, int volume, int days, std::ostream &outs, int intensity) {


    int setsPerDay = getSetsPerWeek(volume, days)/days;

    int numExercisesPerDay;

    int i;

    outs << "\nHere is your personalized workout plan:\n " << std::endl;

    if (days == 1) {
        numExercisesPerDay = 3;
        outs << "Day 1\n-----\n";
        for (i = 0; i < numExercisesPerDay; i++) {
            if ((FULL_BODY_EXERCISE_TYPE[i])[1] == 'C')
                outs << FULL_BODY_EXERCISE_TYPE[i] + " " + std::to_string(setsPerDay/numExercisesPerDay) + COMPOUND_REPS << std::endl;
            else
                outs << FULL_BODY_EXERCISE_TYPE[i] + " " + std::to_string(setsPerDay/numExercisesPerDay) + ACCESSORY_REPS << std::endl;

        }
        outs << "You chose " + areaOfFocus + " as your area of focus. Add 1 extra set to one of the above " + areaOfFocus + " exercises.";
    } else if (days == 2) {
        numExercisesPerDay = 4;
        printWorkout(numExercisesPerDay, areaOfFocus, setsPerDay, days, outs);
    } else if (days == 3) {
        numExercisesPerDay = 4;
        printWorkout(numExercisesPerDay, areaOfFocus, setsPerDay, days, outs);
    } else if (days == 4) {
        numExercisesPerDay = 4;
        printWorkout(numExercisesPerDay, areaOfFocus, setsPerDay, days, outs);
    } else {
        numExercisesPerDay = 5;
        printWorkout(numExercisesPerDay, areaOfFocus, setsPerDay, days, outs);
    }

    if (intensity == 1)
        outs << "\nYou chose " << intensity << " intensity. This means you should train 4 rep(s) away from failure.\n";
    else if (intensity == 2)
        outs << "\nYou chose " << intensity << " intensity. This means you should train 3 rep(s) away from failure.\n";
    else if (intensity == 3)
        outs << "\nYou chose " << intensity << " intensity. This means you should train 2 rep(s) away from failure.\n";
    else if (intensity == 4)
        outs << "\nYou chose " << intensity << " intensity. This means you should train 1 rep(s) away from failure.\n";
    else
        outs << "\nYou chose " << intensity << " intensity. This means you should train to failure on every single set. "
                                                  "IT IS NOT RECOMMENDED TO DO THIS ON EVERY SET AS YOU WILL ACCUMULATE"
                                                  " A LOT OF FATIGUE. Consider only training to failure on your last set\n";


}

int WorkoutRecommendations::stringToInt(std::string numberString) {

    std::vector<std::string> numbers {"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN"};
    int numberInt = 0;
    int i;

    // checks to see if number is in word or integer form
    if (numberString.length() > 1) {

        // looks for index where number in word form is and then adds 1 to it to find the equivalent number in int form
        for(i = 0; i < numbers.size(); i++) {

            if (numberString == numbers[i]) {
                numberInt = i + 1;
                break;
            }

        }

    } else {

        // simple converts number in integer string form to integer
        numberInt = stoi(numberString);

    }

    return numberInt;
}


int WorkoutRecommendations::getSetsPerWeek(int volume, int days) {

    if (days == 1) {
        if (volume == 1)
            return 6;
        else if (volume == 2) {
            return 9;
        }
        else if (volume == 3) {
            return 12;
        }
        else if (volume == 4) {
            return 15;
        }
        else {
            return 18;
        }
    } else if (days == 2) {
        if (volume == 1)
            return 12;
        else if (volume == 2) {
            return 18;
        }
        else if (volume == 3) {
            return 24;
        }
        else if (volume == 4) {
            return 30;
        }
        else {
            return 36;
        }
    } else if (days == 3) {
        if (volume == 1)
            return 18;
        else if (volume == 2) {
            return 27;
        }
        else if (volume == 3) {
            return 36;
        }
        else if (volume == 4) {
            return 45;
        }
        else {
            return 54;
        }
    } else if (days == 4) {
        if (volume == 1)
            return 24;
        else if (volume == 2) {
            return 36;
        }
        else if (volume == 3) {
            return 48;
        }
        else if (volume == 4) {
            return 60;
        }
        else {
            return 72;
        }
    } else {
        if (volume == 1)
            return 30;
        else if (volume == 2) {
            return 45;
        } else if (volume == 3) {
            return 60;
        } else if (volume == 4) {
            return 75;
        } else {
            return 90;
        }
    }

}

void WorkoutRecommendations::printWorkout(int numExercisesPerDay, std::string aof, int setsPerDay, int days, std::ostream &outs) {

    // variable that counts the amount of exercises a certain muscle group has. Does not want to exceed 3
    int exerciseCountPerDay = 0;


    /*
     * I made a map in order to access the accessory indices for legs, chest, and back. This makes it easier to add
     * a couple of sets to the workout for the user's area of focus as I won't have to use conditionals later on.
     */
    std::map<std::string, int> accessoryIndices {
            {"ARMS", 3}, // "AA" is at index 3
            {"CHEST", 4}, // "CA" is at index 4
            {"BACK", 5}, // "BA" is at index 5
            {"LEGS", 6}, // "LA" is at index 6
    };

    // set extra sets for area of focus equal to 2 for now.
    const std::string EXTRA_SETS = "2";

    int i,j;

    if (days == 2 || days == 3) {
        for (j = 1; j <= days; j++) {
            outs << "Day " + std::to_string(j) + "\n-----\n";
            for (i = 0; i < numExercisesPerDay; i++) {
                if ((FULL_BODY_EXERCISE_TYPE[i])[1] == 'C')
                    outs << FULL_BODY_EXERCISE_TYPE[i] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                         << std::endl << std::endl;
                else
                    outs << FULL_BODY_EXERCISE_TYPE[i] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                         << std::endl << std::endl;
            }

        }
        if (areaOfFocus != "NONE") {
            outs << "Since " << areaOfFocus << " was your preferred area of focus, add these sets to your workout above:" << std::endl;
            outs << FULL_BODY_EXERCISE_TYPE[accessoryIndices.at(areaOfFocus)] << " " << EXTRA_SETS << ACCESSORY_REPS << std::endl << std::endl;
        }
    } else if (days == 4){

        /* This loop goes through which day it is and biases different muscles on different days
         * For example day 3 is back day and day 1 is chest day but the other 2 days are lower body days
        */
        for (j = 1; j <= days; j++) {
            outs << "Day " + std::to_string(j) + "\n-----\n";
            for (i = 1; i <= numExercisesPerDay; i++) {
                // Check to see if it's an even or odd day. used to separate muscle groups into multiple days
                if (j % 2 == 0) {
                    if (i == 1)
                        outs << LOWER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                             << std::endl << std::endl;
                    else
                        outs << LOWER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                             << std::endl << std::endl;
                } else {
                    if (i == 1) {
                        if (j == 3)
                            outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                 << std::endl << std::endl;
                        else
                            outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                 << std::endl << std::endl;
                    } else {
                        if (j == 3) {
                            if (i == 4)
                                outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                     << std::endl << std::endl;
                            else {
                                exerciseCountPerDay++;
                                if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                    outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                         << std::endl << std::endl;
                                else
                                    outs << UPPER_BODY_EXERCISE_TYPE[3] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                            }
                        }
                        else {
                            if (i == 4)
                                outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                 << std::endl << std::endl;
                            else {
                                exerciseCountPerDay++;
                                if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                    outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                         << std::endl << std::endl;
                                else
                                    outs << UPPER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                            }
                        }
                    }
                }
            }
            exerciseCountPerDay = 0;
        }
        outs << "Since " << areaOfFocus << " was your preferred area of focus, add these sets to your workout above:" << std::endl;
        outs << FULL_BODY_EXERCISE_TYPE[accessoryIndices.at(areaOfFocus)] << " " << EXTRA_SETS << ACCESSORY_REPS << std::endl << std::endl;

    } else {
        if (areaOfFocus == "ARMS") {
            for (j = 1; j <= days; j++) {
                outs << "Day " + std::to_string(j) + "\n-----\n";
                for (i = 1; i <= numExercisesPerDay; i++) {
                    // Check to see if it's an even or odd day. used to separate muscle groups into multiple days
                    if (j % 2 == 0) {
                        if (i == 1)
                            outs << LOWER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                 << std::endl << std::endl;
                        else
                            outs << LOWER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                 << std::endl << std::endl;
                    } else if (j != 5){
                        if (i == 1) {
                            if (j == 3)
                                outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                     << std::endl << std::endl;
                            else
                                outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                     << std::endl << std::endl;
                        } else {
                            if (j == 3) {
                                if (i == 4)
                                    outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                                else {
                                    exerciseCountPerDay++;
                                    if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                        outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                             << std::endl << std::endl;
                                    else
                                        outs << UPPER_BODY_EXERCISE_TYPE[3] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                             << std::endl << std::endl;
                                }
                            }
                            else {
                                if (i == 4)
                                    outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                                else {
                                    exerciseCountPerDay++;
                                    if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                        outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                             << std::endl << std::endl;
                                    else
                                        outs << UPPER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                             << std::endl << std::endl;
                                }
                            }
                        }
                    } else {
                        outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                             << std::endl << std::endl;
                    }
                }
                exerciseCountPerDay = 0;
            }
            outs << "Since " << areaOfFocus << " was your preferred area of focus, I made day 5 entirely dedicated to "<< areaOfFocus << std::endl;
        } else {
            for (j = 1; j <= days; j++) {
                outs << "Day " + std::to_string(j) + "\n-----\n";
                for (i = 1; i <= numExercisesPerDay; i++) {
                    // Check to see if it's an even or odd day. used to separate muscle groups into multiple days
                    if (j % 2 == 0) {
                        if (i == 1)
                            outs << LOWER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                 << std::endl << std::endl;
                        else
                            outs << LOWER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                 << std::endl << std::endl;
                    } else {
                        if (i == 1) {
                            if (j == 3)
                                outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                     << std::endl << std::endl;
                            else
                                outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                     << std::endl << std::endl;
                        } else {
                            if (j == 3) {
                                if (i == 4)
                                    outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                                else {
                                    exerciseCountPerDay++;
                                    if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                        outs << UPPER_BODY_EXERCISE_TYPE[0] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                             << std::endl << std::endl;
                                    else
                                        outs << UPPER_BODY_EXERCISE_TYPE[3] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                             << std::endl << std::endl;
                                }
                            }
                            else {
                                if (i == 4)
                                    outs << UPPER_BODY_EXERCISE_TYPE[4] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                         << std::endl << std::endl;
                                else {
                                    exerciseCountPerDay++;
                                    if (exerciseCountPerDay == MAX_EXERCISES_ACCESSORY)
                                        outs << UPPER_BODY_EXERCISE_TYPE[2] + " " + std::to_string(setsPerDay / numExercisesPerDay) + COMPOUND_REPS
                                             << std::endl << std::endl;
                                    else
                                        outs << UPPER_BODY_EXERCISE_TYPE[1] + " " + std::to_string(setsPerDay / numExercisesPerDay) + ACCESSORY_REPS
                                             << std::endl << std::endl;
                                }
                            }
                        }
                    }
                }
                exerciseCountPerDay = 0;
            }
        }

    }





}
