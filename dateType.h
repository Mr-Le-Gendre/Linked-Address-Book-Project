#ifndef H_dateType
#define H_dateType

class dateType
{
public:
    void setDate(int month, int day, int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void printDate() const;

    dateType(int month = 1, int day = 1, int year = 1900);

private:
    int dMonth{ 1 };
    int dDay{ 1 };
    int dYear{ 1900 };
};

#endif
