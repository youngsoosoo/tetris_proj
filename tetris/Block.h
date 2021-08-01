#pragma once

#include "main.h"

class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x좌표
    int y; // y좌표
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]로 4가지 상태 표현
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
    /*1번 블럭*/
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
    /*2번 블럭*/
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
    /*3번 블럭*/
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
    /*4번 블럭*/
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
    /*5번 블럭*/
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
    // 6번 블럭
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
    // 7번 블럭
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