#include <iostream>

class Vector
{
private:
    unsigned int length = 0;
    std::string *array;

public:
    unsigned long long int size()
    {
        return length;
    }

    std::string at(unsigned int index)
    {
        if (index >= length)
        {
            std::cerr << "The index is out of range" << std::endl;
            exit(1);
        }

        return array[index];
    }

    void add(std::string item)
    {
        std::string *new_array = new std::string[length + 1];
        for (unsigned long long int i = 0; i < length; i++)
        {
            new_array[i] = array[i];
        }

        new_array[length] = item;

        array = new_array;
        length++;
    }

    void remove(unsigned long long int index)
    {
        if (index >= length)
        {
            std::cerr << "The index is out of range" << std::endl;
            exit(1);
        }

        std::string *new_array = new std::string[length - 1];

        for (unsigned long long int i = 0, j = 0; i < length; i++)
        {
            if (i == index)
            {
                continue;
            }

            new_array[j] = array[i];
            j++;
        }

        array = new_array;
        length--;
    }

    std::string join(std::string str)
    {
        std::string result = "";

        if (length == 0)
        {
            return result;
        }

        for (unsigned long long int i = 0; i < length - 1; i++)
        {
            result += array[i] + str;
        }

        result += array[length - 1];

        return result;
    }

    friend void print(Vector& vect);

    void forEach(void callBack(std::string item, unsigned long long int index)) {
        for (unsigned long long int i = 0;i < length;i++) {
            callBack(array[i],i);
        }
    }
};

Vector split(std::string str, std::string separator) {
    Vector array;

    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.substr(i, separator.size()) == separator)
        {
            array.add(str.substr(j, i - j));
            j = i + separator.size();
        }
    }

    if (j < str.size() - 1)
    {
        array.add(str.substr(j, str.size()));
    }

    return array;
}


void print(Vector& vect) {
    std::cout << "[";

    if (vect.length == 0)
    {
        std::cout << "]" << std::endl;
        return;
    }

    for (unsigned long long int i = 0; i < vect.length - 1; i++)
    {
        std::cout<< " " << vect.array[i] << " ,";
    }

    std::cout << vect.array[vect.length - 1] << " ]" << std::endl;
}


void print(std::string str, std::string end = "") {
    if (end == "") {
        std::cout<<str<<std::endl;
        return;
    }
    
    std::cout<<str<<end;
}
