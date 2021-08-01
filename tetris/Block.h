#pragma once

#include "main.h"

class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x��ǥ
    int y; // y��ǥ
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]�� 4���� ���� ǥ��
public:
    int GetShape(int ratationCount, int y, int x) {
        return shape[ratationCount][y][x];
    }
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
};

class Block1 : Block
{
private:
    /*1�� ��*/
    const int block1[4][4][4] = {
            {
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {2, 2, 2, 2},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 2, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {2, 2, 2, 2},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 2, 0}
            },
    };
public:
    Block1() 
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k];
                }
            }
        }
    }
};

class Block2 : Block
{
private:
    /*2�� ��*/
    const int block2[4][4][4] = {
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block2()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k];
                }
            }
        }
    }
};

class Block3 : Block
{
private:
    /*3�� ��*/
    const int block3[4][4][4] = {
            {
                            {0, 2, 0, 0},
                            {0, 2, 0, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 2},
                            {0, 2, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 2, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 0, 2, 0},
                            {2, 2, 2, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block3()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k];
                }
            }
        }
    }
};

class Block4 : Block
{
private:
    /*4�� ��*/
    const int block4[4][4][4] = {
            {
                            {0, 0, 0, 0},
                            {0, 2, 0, 0},
                            {0, 2, 2, 0},
                            {0, 0, 2, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {2, 2, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 0, 0},
                            {0, 2, 2, 0},
                            {0, 0, 2, 0}
            },
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 0},
                            {2, 2, 0, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block4()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k];
                }
            }
        }
    }
};

class Block5 : Block
{
private:
    /*5�� ��*/
    const int block5[4][4][4] = {
            {
                            {0, 0, 0, 0},
                            {0, 2, 2, 2},
                            {0, 0, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 2, 2, 2},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 0, 2, 2},
                            {0, 0, 2, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block5()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k];
                }
            }
        }
    }
};

class Block6 : Block
{
private:
    // 6�� ��
    const int block6[4][4][4] = {
            {
                            {0, 0, 2, 0},
                            {0, 0, 2, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {2, 0, 0, 0},
                            {2, 2, 2, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 2, 2, 0},
                            {0, 2, 0, 0},
                            {0, 2, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 0, 0},
                            {2, 2, 2, 0},
                            {0, 0, 2, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block6()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block6[i][j][k];
                }
            }
        }
    }
};

class Block7 : Block
{
private:
    // 7�� ��
    const int block7[4][4][4] = {
            {
                            {0, 0, 2, 0},
                            {0, 2, 2, 0},
                            {0, 2, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {2, 2, 0, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {0, 0, 2, 0},
                            {0, 2, 2, 0},
                            {0, 2, 0, 0},
                            {0, 0, 0, 0}
            },
            {
                            {2, 2, 0, 0},
                            {0, 2, 2, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}
            },
    };
public:
    Block7()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block7[i][j][k];
                }
            }
        }
    }
};