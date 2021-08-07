#include "Block.h"

const int Block::SHAPE[7][4][4][2] = {
    //I
    { { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
    { {-2, 0}, {-1, 0}, {0, 0}, {1, 0} },
    { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
    { {-2, 0}, {-1, 0}, {0, 0}, {1, 0} } },
    //L
    { { {0, -1}, {0, 0}, {0, 1}, {1, 1} },
    { {-1, 0}, {0, 0}, {1, 0}, {-1, 1} },
    { {-1, -1}, {0, -1}, {0, 0}, {0, 1} },
    { {1, -1}, {-1, 0}, {0, 0}, {1, 0} } },
    //RL
    { { {0, -1}, {0, 0}, {-1, 1}, {0, 1} },
    { {-1, -1}, {-1, 0}, {0, 0}, {1, 0} },
    { {0, -1}, {1, -1}, {0, 0}, {0, 1} },
    { {-1, 0}, {0, 0}, {1, 0}, {1, 1} } },
    //T
    { { {0, -1}, {-1, 0}, {0, 0}, {0, 1} },
    { {0, -1}, {-1, 0}, {0, 0}, {1, 0} },
    { {0, -1}, {0, 0}, {1, 0}, {0, 1} },
    { {-1, 0}, {0, 0}, {1, 0}, {0, 1} } },
    //O
    { { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1}, {1, 1} }, },
    //S
    { { {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
    { {-1, -1}, {-1, 0}, {0, 0}, {0, 1} },
    { {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
    { {-1, -1}, {-1, 0}, {0, 0}, {0, 1} } },
    //RS
    { { {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
    { {0, -1}, {-1, 0}, {0, 0}, {-1, 1} },
    { {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
    { {0, -1}, {-1, 0}, {0, 0}, {-1, 1} } }
};

Block::Block(int _rotation, int _name) : name(_name), rotation(_rotation) {
    x = CREATE_X;
    y = CREATE_Y;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++)
        {
            shape[i][j] = SHAPE[_name][_rotation][i][j];
        }
    }
    PrintBlock();
}

int Block::GetX() {
    return x;
}
int Block::GetY() {
    return y;
}
int Block::GetRotation() {
    return rotation;
}

void Block::PrintBlock() {
    for (int i = 0; i < 4; i++) {
        Cursor(x + (2 * shape[i][0]), y + shape[i][1]);
        cout << "бс";
    }
}

void Block::RotationBlock() {
    int tempshape[4][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            tempshape[i][j] = SHAPE[name][(rotation + 1) % 4][i][j];
        }
            if (GameTable::IsBlock(x + (tempshape[i][0] * 2), y + tempshape[i][1])
                || !(GameTable::IsInTable(x + (tempshape[i][0] * 2)))) {
                return;
            }
    }
    rotation = (rotation + 1) % 4;
    DeleteBlock();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++)
        {
            shape[i][j]= SHAPE[name][rotation][i][j];
        }
    }
    
    PrintBlock();
}

void Block::ShiftBlock(int _x, int _y) {
    for (int i = 0; i < 4; i++) {
        if (GameTable::IsBlock(x + (shape[i][0] * 2) + _x, y + shape[i][1] + _y)
            || !(GameTable::IsInTable(x + (shape[i][0]*2) + _x))) {
            return;
        }
    }
    DeleteBlock();
    x += _x;
    y += _y;
    PrintBlock();
}

void Block::DeleteBlock() {
    for (int i = 0; i < 4; i++) {
        Cursor(x + (2 * shape[i][0]), y + shape[i][1]);
        cout << "  ";
    }
}

void Block::FixBlock() {
    
}

