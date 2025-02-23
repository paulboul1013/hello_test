#pragma once
#ifndef intcell_H
#define intcell_H

class IntCell{
    private:
        int value;
    public:
        
     IntCell(int value=0);
     int read()const;
     void write(int x);
};


#endif