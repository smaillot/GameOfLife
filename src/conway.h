struct Cell {int x; int y; bool alive;};
struct Map {bool world[10][10]; bool next_world[10][10]; int rows; int cols;};

int initall(void);
int enditall(void);

void display(struct Cell*);
int count_neighbors(struct Cell*, struct Map*);

bool get_next_state (struct Cell*, struct Map*);