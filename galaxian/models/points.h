/**
 * The Points class represents the points of the player in the game.
*/
class Points {
public:
    /**
     * The Values enum represents the different values of the aliens.
    */
    enum Values {
        GREEN_FORMATION = 30,
        GREEN_ATTACK = 60,
        BLUE_FORMATION = 40,
        BLUE_ATTACK = 80,
        RED_FORMATION = 50,
        RED_ATTACK = 100,
        FLAGSHIP_FORMATION = 60,
        FLAGSHIP_ATTACK_SOLO = 150,
        FLAGSHIP_ATTACK_DUO = 200,
        FLAGSHIP_ATTACK_TRIO_NOT_LAST = 300,
        FLAGSHIP_ATTACK_TRIO_LAST = 800
    };
    /**
     * Adds points to the player's score.
     * @param value The value of the alien that was destroyed.
    */
    void addPoints(Values value);
    int getPoints();
    /**
     * Resets the points of the player to 0.
    */
    void resetPoints();
    int getHighscore();
    void setHighscore(int highscore);
    void setHighscore();
private:
    /**
     * The current points of the player.
    */
    int points = 0;
    int highscore = 0;
};