class game
{
    char play[3][3];
    int r, c;
    bool end_game;
public:
    void display();
    void start();
    bool stop();
    bool win( char turn);
    void pc_play(char turn);
    void player_play(char turn);
    bool check_3(char turn);
    bool pl_check_3(char turn);
};
