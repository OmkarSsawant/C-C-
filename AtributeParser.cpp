#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;



int main()
{

  int hrmli = 0, qt = 0;

  cin >> hrmli >> qt;

  if (1 <= (qt && hrmli) <= 20)
  {
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
          //remove if there is closing tag continuous
          int loclose = sepstr.find('>');
          if (loclose > 0)
          {
            auto ref = sepstr.erase(loclose);
          }
          prevTags[++i] = sepstr.substr(1);
          // cout<<"Opening Tag : "<<sepstr.substr(1)<<endl;
        }
        else if (sepstr.substr(0, 2) == "</")
        {
          //its an closing sepstr
          string clTag = sepstr.substr(2, sepstr.length() - 3);


          //remove the opening tag from array
          for (string *p = prevTags; p != lep; p++)
          {
            if (*p == "")
              continue;

            if (*p == clTag)
            {
              *p = "";
              // delete p; //! TODO: not for net
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
          sepstr = sepstr.substr(1);
          sepstr.erase(sepstr.find_last_of('"'));

          // cout << "Value : " << sepstr << endl;
          if (attr != "")
          {
            string key = "";
            for (string *itr = prevTags; itr != lep; itr++)
            {
              if (*itr == "")
                continue;

              if (key == "")
                key.append(*itr);
              else
              {
                key.append("." + *itr);
              }
            }
            key += "~" + attr;

            //full query
            attrv.insert(make_pair(key, sepstr));
           
            attr = "";
          }
        }
        else
        {
          //its an attribute
          if (sepstr != "=")
          {
            attr = sepstr;
            // cout << "Attributes  : " << attr << endl;
          }
        }
      }
    }

    for (int it = 0; it < qt; it++)
    {
      string query;
      cin >> query;
      if (attrv.find(query) == attrv.end())
        cout << "Not Found!" << endl;
      else
        cout << attrv.at(query) << endl;
    }
    //free up the allocated array memory
    //! TODO:  remove during HackerRank
    // delete[] prevTags;
  }

  return 0;
}

//just a sinnipet with which you can create sublinks 
//eg . tag1.tag2.tag3~attr can be also called tag1.tag3~attr
//use at line 104
// ⚠️ caution not to use in submission code  
/*
           int ldotIndex = key.find_last_of('.');

            if (ldotIndex > 0)
            {

               has parents
              string mainq = key.substr(ldotIndex).substr(1);

              string evalstr = key.substr(0, key.length() - mainq.length());

              stringstream sst(evalstr);
              string ext;
              cout << "SubRoutes   ... " << endl;
              while (getline(sst, ext, '.'))
              {
                attrv.insert(make_pair(ext + "." + mainq, sepstr));
                cout << ext + "." + mainq << "  " << sepstr << endl;
              }
            }
 */
