#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
using namespace std;

class newInt
{
    friend istream& operator>>(istream& in, newInt& a);
    friend ostream& operator<<(ostream& out, newInt& a);
public:
    newInt(int a = 0)
    {
        _a = a;
    }

    newInt operator+(newInt& b)
    {
        newInt ret;
        unsigned flag = 10;
        ret._a = _a + b._a;
        while (ret._a / flag > 0)
        {
            if ((_a % flag) / (flag / 10) + (b._a % flag) / (flag / 10) > 9)
                ret._a -= flag;

            flag *= 10;
        }
        return ret;
    }

private:
    int _a;
};

istream& operator>>(istream& in, newInt& a)
{
    in >> a._a;
    return in;
}

ostream& operator<<(ostream& out, newInt& a)
{
    out << a._a;
    return out;
}

int main()
{
    int cases;
    newInt a, b, c;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> a >> b;
        c = a + b;
        cout << a << " + " << b << " = " << c << endl;
    }
    return 0;
}


class Array
{
    friend istream& operator>>(istream& in, Array& a);
    friend ostream& operator<<(ostream& out, Array& a);

public:

    Array()
    {
        length = 0;
        nums = NULL;
    }

    bool operator==(Array& a)
    {
        if (this == &a)
            return true;

        if (length != a.length)
            return false;

        for (int i = 0; i < length; i++)
        {
            if (nums[i] != a.nums[i])
                return false;
        }

        return true;
    }

private:
    int length;
    int* nums;
};


istream& operator>>(istream& in, Array& a)
{
    in >> a.length;
    a.nums = new int[a.length];

    for (int i = 0; i < a.length; i++)
    {
        in >> a.nums[i];
    }
    return in;
}

ostream& operator<<(ostream& out, Array& a)
{
    for (int i = 0; i < a.length; i++)
    {
        if (i)
            out << " ";

        out << a.nums[i];
    }

    return out;
}

int main()
{
    int cases;
    cin >> cases;
    Array arraies[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> arraies[i];
    }
    cout << arraies[0] << endl;
    for (int i = 1; i < cases; i++)
    {
        if (arraies[i] == arraies[i - 1])
        {
            cout << arraies[i] << " " << "equal to above." << endl;
        }
        else
        {
            cout << arraies[i] << " " << "unequal to above." << endl;
        }
    }
    return 0;
}

class Student
{
    friend ostream& operator<<(ostream& out, Student& stu);

public:
    Student()
    {
        name = " ";
        score = 0;
    }

    void setStudent(string s, int a)
    {
        name = s;
        score = a;
    }

    bool operator>(Student& stu)
    {
        if (score > stu.score || (score == stu.score && name < stu.name))
        {
            return true;
        }

        return false;
    }

private:
    string name;
    int score;
};



ostream& operator<<(ostream& out, Student& stu)
{
    out << stu.score << " " << stu.name;
}

int main()
{
    int cases;
    string name;
    int score;
    cin >> cases;
    Student students[cases], temp;
    for (int i = 0; i < cases; i++)
    {
        cin >> name >> score;
        students[i].setStudent(name, score);
    }
    for (int i = 0; i < cases; i++)
    {
        for (int j = 0; j < cases - i - 1; j++)
        {
            if (!(students[j] > students[j + 1]))
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < cases; i++)
        cout << students[i] << endl;
    return 0;
}

class Animal
{
public:

    Animal()
    {
        name = " ";
        num = 0;
    }

    void setAnimal(string s, int a)
    {
        name = s;
        num = a;
    }

    int getNum()const
    {
        return num;
    }

    string getName()const
    {
        return name;
    }

    Animal& operator=(const Animal& animal)
    {
        if (this != &animal)
        {
            name = animal.name;
            num = animal.num;
        }
    }

    friend class AnimalList;
private:
    string name;
    int num;
};


class AnimalList
{
public:


    AnimalList(Animal* animals, int n)
    {
        nums = n;
        animalList = new Animal[n];

        for (int i = 0; i < nums; i++)
        {
            animalList[i] = animals[i];
        }
    }

    int operator[](string name)
    {
        for (int i = 0; i < nums; i++)
        {
            if (animalList[i].name == name)
                return animalList[i].num;
        }

        return -1;
    }

private:
    Animal* animalList;
    int nums;
};

int main()
{
    int cases;
    string name;
    int num;
    cin >> cases;
    Animal animals[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> name >> num;
        animals[i].setAnimal(name, num);
    }
    AnimalList animalList(animals, cases);

    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> name;
        if (animalList[name] != -1)
            cout << "There are " << animalList[name] << " " << name << "s." << endl;
        else
            cout << "There is none " << name << "." << endl;
    }
    return 0;
}

class MyList
{
public:
    MyList(int _len)
    {
        capacity = _len;
        len = 0;
        a = (int*)malloc(sizeof(int) * _len);

        if (a == NULL)
            return;
    }

    void append(int d)
    {
        if (capacity == len)
        {
            int newcapacity = capacity * 2;
            int* tmp = a;
            tmp = (int*)realloc(a, sizeof(int) * newcapacity);

            if (tmp == NULL)
                return;

            a = tmp;
            capacity = newcapacity;
        }
        a[len++] = d;
    }

    void insert(int p, int d)
    {
        if (capacity == len)
        {
            int newcapacity = capacity * 2;
            int* tmp = a;
            tmp = (int*)realloc(a, sizeof(int) * newcapacity);

            if (tmp == NULL)
                return;

            a = tmp;
            capacity = newcapacity;
        }

        for (int i = len - 1; i >= p; i--)
        {
            a[i + 1] = a[i];
        }

        a[p] = d;
        len++;
    }

    void erase(int p)
    {
        for (int i = p; i < len; i++)
        {
            a[i] = a[i + 1];
        }
        len--;
    }

    void set(int p, int d)
    {
        a[p] = d;
    }

    void show()
    {
        for (int i = 0; i < len; i++)
        {
            if (i)
                cout << " ";
            cout << a[i];
        }
    }

    ~MyList()
    {
        free(a);
        a = NULL;
        len = capacity = 0;
    }
private:
    int* a;
    int len;
    int capacity;
};

int main()
{
    int cases, len, data, pos;
    char op;
    cin >> len;
    MyList myList(len);
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> op;
        switch (op)
        {
        case 'A':
            cin >> data;
            myList.append(data);
            break;
        case 'I':
            cin >> pos >> data;
            myList.insert(pos, data);
            break;
        case 'E':
            cin >> pos;
            myList.erase(pos);
            break;
        case 'S':
            cin >> pos >> data;
            myList.set(pos, data);
        }
        myList.show();
    }
    return 0;
}