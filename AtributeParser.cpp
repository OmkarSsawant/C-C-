#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

bool contains(string query, map<string, string> attrm)
{
    map<string, string>::iterator mi = attrm.begin();

    for (mi; mi != attrm.end(); mi++)
    {
        if (mi->first == query)
            return true;
    }

    return false;
}

int main()
{

    int hrmli = 0, qt = 0;

    cin >> hrmli >> qt;

    string hrml = "";

    for (int i = 0; i <= hrmli; i++)
    {
        string t;
        getline(cin, t);
        hrml.append(t + " ");
    }

    string sepstr = "";

    string *prevTags = new string[hrmli]; //based on input

    string *lep = &prevTags[hrmli]; //last element pointer

    int i = -1;

    string attr = "";

    map<string, string> attrv;

    stringstream ss(hrml);

    while (getline(ss, sepstr, ' '))
    {
        if (sepstr.length() > 0)
        {
            if (sepstr.at(0) == '<' && sepstr.at(1) != '/')
            {
                //its an opening sepstr
                prevTags[++i] = sepstr.substr(1);
            }
            else if (sepstr.substr(0, 2) == "</")
            {
                //its an closing sepstr
                string clTag = sepstr.substr(2, sepstr.length() - 3);

                //remove the opening tag from array
                for (string *p = prevTags; p != lep; p++)
                {
                    if (*prevTags == "")
                        break;
                    if (*prevTags == clTag)
                    {
                        delete prevTags;
                        //get back the assign index
                        if (i != -1)
                            i--;
                    }
                }
            }
            else if (sepstr.at(0) == 34)
            {
                //its an value
                //remove *
                sepstr.pop_back();
                sepstr.pop_back();
                sepstr = sepstr.substr(1);
                if (attr != "")
                {
                    string key = "";
                    for (string *itr = prevTags; itr != lep; itr++)
                    {
                        if (*itr == "")
                            break;

                        if (key == "")
                            key.append(*itr);
                        else
                        {
                            key.append("." + *itr);
                        }
                    }
                    key += "~" + attr;
                    attrv.insert(make_pair(key, sepstr));
                    attr = "";
                }
            }
            else
            {
                //its an attribute
                if (sepstr != "=" && sepstr != ">")
                {
                    attr = sepstr;
                }
            }
        }
    }


    for (int i = 0; i < qt; i++)
    {
        string query;
        cin >> query;
        if (contains(query, attrv))
            cout << attrv.at(query) << endl;
        else
            cout << "Not Found!" << endl;
    }

    //free up the allocated array memory
    delete[] prevTags;

    return 0;
}
