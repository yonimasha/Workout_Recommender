#include <iostream>
#include "WorkoutRecommendations.h"

int main() {

    WorkoutRecommendations workoutSchedule;
    int intensity;
    int volume;
    int days;
    std::string areaOfFocus;
    std::string input;

    bool runProgram = true;
    bool checkIfValid = true;

    workoutSchedule.printIntroduction(std::cout);

    while (runProgram) {

        std::cout << "\n1) I give you a personal workout.\n2) You personalize how you want your workout to look.\n"
                     "Please input either 1 or 2: ";

        getline(std::cin, input);
        input = workoutSchedule.convertString(input);

        while (input != "1" && input != "2" && input != "ONE" && input != "TWO") {
            std::cout << "Please input either 1 or 2: ";
            getline(std::cin, input);
            input = workoutSchedule.convertString(input);
        }

        if (input == "2" || input == "TWO") {

            workoutSchedule.setDayPerWeek(workoutSchedule.getUserDays(std::cout, std::cin));
            workoutSchedule.setIntensity(workoutSchedule.getUserIntensity(std::cout, std::cin));
            workoutSchedule.setVolume(workoutSchedule.getUserVolume(std::cout, std::cin));
            workoutSchedule.setAreaOfFocus(workoutSchedule.getUserAOF(std::cout, std::cin));

            intensity = workoutSchedule.getIntensity();
            volume = workoutSchedule.getVolume();
            days = workoutSchedule.getDaysPerWeek();
            areaOfFocus = workoutSchedule.getAreaOfFocus();

            workoutSchedule.getWorkout(areaOfFocus, volume, days, std::cout, intensity);

            std::cout << "\nWould you like to make another workout? (Y/N/Yes/No) : ";

            getline(std::cin, input);

            input = workoutSchedule.convertString(input);

            while(checkIfValid) {
                if (input == "") {
                    std::cout << "No input. Please input either Y/N/Yes/No : ";
                    getline(std::cin, input);
                    input = workoutSchedule.convertString(input);
                }
                else if (input != "Y" && input != "N" && input != "YES" && input != "NO") {
                    std::cout << "I'm not sure I understand. Please input either Y/N/Yes/No : ";
                    getline(std::cin, input);
                    input = workoutSchedule.convertString(input);
                }
                else {
                    checkIfValid = false;
                }
            }

            if (input == "N" || input == "NO")
                runProgram = false;

        } else {

            intensity = workoutSchedule.getIntensity();
            volume = workoutSchedule.getVolume();
            days = workoutSchedule.getDaysPerWeek();
            areaOfFocus = workoutSchedule.getAreaOfFocus();

            workoutSchedule.getWorkout(areaOfFocus, volume, days, std::cout, intensity);

            std::cout << "\nWould you like to make another workout? (Y/N/Yes/No) : ";

            getline(std::cin, input);

            input = workoutSchedule.convertString(input);

            while(checkIfValid) {
                if (input == "") {
                    std::cout << "No input. Please input either Y/N/Yes/No : ";
                    getline(std::cin, input);
                    input = workoutSchedule.convertString(input);
                }
                else if (input != "Y" && input != "N" && input != "YES" && input != "NO") {
                    std::cout << "I'm not sure I understand. Please input either Y/N/Yes/No : ";
                    getline(std::cin, input);
                    input = workoutSchedule.convertString(input);
                }
                else {
                    checkIfValid = false;
                }
            }

            if (input == "N" || input == "NO")
                runProgram = false;
        }
        checkIfValid = true;
    }




    return 0;
}
