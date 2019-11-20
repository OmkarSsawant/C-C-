#include <iostream>
#include <typeinfo>
#include <sstream>
#include<vector>
#include<set>
#include<map>
using namespace std;

class TypeName{
public:
     template <class T>
   static std::string gettypeof(T);

     template <class T>
   static  std::string gettypeof(set<T>);

     template <class T>
     static std::string gettypeof(vector<T>);


     template <class key, class value>
   static  std::string gettypeof(map<key, value>);
};

template <class T>
std::string TypeName::gettypeof(T var)
{
    auto type = typeid(var).name();
    std::stringstream ss(type);
    std::string c;
    ss >> c;
    if (c == "c")
        return "character";
    else if (c == "f")
        return "float";
    else if (c == "d")
        return "double";
    else if (c == "i")
        return "int";
    else if (c == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")
        return "string";
    else if (c == "Pc")
        return "pointer of char";
    else if (c == "Pi")
        return "pointer of int";
    else if (c == "Pf")
        return "pointer of float";
    else if (c == "Pd")
        return "pointer of double";
    else
        return "STL iterator";
}

template <class T>
std::string TypeName::gettypeof(set<T> s)
{

    T sb;
    std::string setof = gettypeof(sb);
    std::string ret = "set <" + setof + ">";
    return ret;
}
template <class T>
std::string TypeName::gettypeof(vector<T> s)
{

    T sb;
    std::string vectorof = gettypeof(sb);

    std::string ret = "vector <" + vectorof + ">";
    return ret;
}
template <class key, class value>
std::string TypeName::gettypeof(map<key, value> s)
{
    key _key;
    value _value;
    std::string keyof = gettypeof(_key);

    std::string valueof = gettypeof(_value);

    std::string ret = "map <" + keyof + " , " + valueof + " >";
    return ret;
}
