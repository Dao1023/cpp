/*
存在问题：是谁在调用类？
虽然我们知道是某个实例在调用，但代码执行到这里时，如果类里面有 year，实例也有，该如何区分？
*/

class Date
{
public:
    void SetDate(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1;
    Date d2;
    d1.SetDate(2021, 2, 20);
    d2.SetDate(2022, 8, 19);
}

/*
我们用 this 来传入实例
这个操作在 Python 中你应该见过，现在会帮你更好理解为啥 Python 这样做
*/

class Date
{
public:
    void SetDate(Date* this, int year, int month, int day)
    {
        this -> _year = year;
        this -> _month = month;
        this -> _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1;
    Date d2;
    d1.SetDate(&d1, 2021, 2, 20);
    d2.SetDate(&d2, 2022, 8, 19);
}