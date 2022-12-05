class section 
{
    public:
        section(int start, int end);
        bool operator<(const section& other) const;
        bool operator<=(const section &other) const;
        int get_start();
        int get_end();
        void new_pair(int start, int end);
    private:
        int start;
        int end;
        int lenght;
};

typedef struct 
{
    int x;
    int y;
} Vector2D;