#ifndef M1OEP_YMASHA_WORKOUTRECOMMENDATIONS_H
#define M1OEP_YMASHA_WORKOUTRECOMMENDATIONS_H


#include <iostream>
#include <vector>

class WorkoutRecommendations {

    int intensity;
    int volume;
    int daysPerWeek;
    std::string areaOfFocus;

    const int MAX_EXERCISES_ACCESSORY = 2;
    const int AVERAGE_WORKOUT = 3;
    const std::string COMPOUND_REPS = "x6-10";
    const std::string ACCESSORY_REPS = "x8-12";
    const std::vector<std::string> FULL_BODY_EXERCISE_TYPE {"CC", "BC", "LC", "AA","CA", "BA", "LA"};
    const std::vector<std::string> UPPER_BODY_EXERCISE_TYPE {"CC", "CA", "BC","BA", "AA"};
    const std::vector<std::string> LOWER_BODY_EXERCISE_TYPE {"LC", "LA"};


public:

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: intensity, volume, daysPerWeek, and metric
     * Effects: nothing other than setting variables equal to their default values
     */
    WorkoutRecommendations();

    // getters
    int getIntensity();

    int getVolume();

    int getDaysPerWeek();

    std::string getAreaOfFocus();


    // setters
    void setIntensity(int userIntensity);

    void setVolume(int userVolume);

    void setDayPerWeek(int userDays);

    void setAreaOfFocus(std::string userAOF);


    // user validation functions
    int getUserIntensity(std::ostream &outs, std::istream &ins);

    int getUserVolume(std::ostream &outs, std::istream &ins);

    int getUserDays(std::ostream &outs, std::istream &ins);

    std::string getUserAOF(std::ostream &outs, std::istream &ins);


    /*
     * Print program introduction
     * Requires: nothing
     * Modifies: nothing
     * Effects: simply prints the programs introduction
     */
    void printIntroduction(std::ostream &outs);

    /*
     * convertString
     * Requires: string
     * Modifies: string
     * Effects: returns a capitalized string that has no spaces and or tabs
     */
    std::string convertString(std::string normalString);

    /*
     * Construct workout
     * Requires: area of focus, volume, days, and std::cout
     * Modifies: nothing
     * Effects: prints out a user's workout depending on what they chose for values for volume,days, and area of focus
     */
    void getWorkout(std::string areaOfFocus, int volume, int days, std::ostream &outs, int intensity);


private:

    /*
     * String to int conversion
     * Requires: number in string either in number form or word form (ex. "1" or "one")
     * Modifies: nothing
     * Effects: Converts string to integer form for later use
     */
    int stringToInt(std::string numberString);

    /*
     * Gets sets per week
     * Requires: volume and days
     * Modifies: nothing
     * Effects: returns a number of sets depending on user's volume and area of focus
     *
     */
    int getSetsPerWeek(int volume, int days);

    /*
     * printWorkout
     * Requires: number of exercises, area of focus, sets per day, days a week, std::cout
     * Modifies: nothing
     * Effects: brings everything together and prints out a users personalized workout plan
     */
    void printWorkout(int numberOfExercises,std::string areaOfFocus, int setsPerDay, int days ,std::ostream &outs);

};

#endif //M1OEP_YMASHA_WORKOUTRECOMMENDATIONS_H
