class Points {
public:
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
    void addPoints(Values value);
    int getPoints();
    void resetPoints();
private:
    int points = 0;
};