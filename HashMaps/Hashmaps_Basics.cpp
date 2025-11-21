#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // Creation
        unordered_map <string, int>m;           

    // Insertion 

        //Method -1 : using pair
        pair <string, int> p1 = make_pair("one", 2);   
        m.insert(p1);

        pair <string, int> p2 ("two", 1);
        m.insert(p2);

        //Method -2 : Using the key
        m["three"] = 1;

    // Searching 
        
        // Method - 1 : Creates and returns 0 for any unknown key
        cout << "Value at two is :  " << m["two"] << endl;
        cout << "Value at four is :  " << m["four"] << endl;
        

        // Method - 2: Throws error and aborts
        cout << "Value at one is :  " << m.at("one") << endl;
        cout << "Value at four is :  " << m.at("four") << endl;           // 0
        //cout << m.at("five") << endl;           // Error

    // Size
        cout << "Size of the map is : " << m.size() << endl;
    
    // to Check presence of an element
        cout << "Value at two is :  " << m.count("two") << endl;
        cout << "Value at six is :  " << m.count("six") << endl;
    
    // Delete
        m.erase("three");
        cout << "Size of the map is : " << m.size() << endl;
    
    // Printi
     
        // Without iterator
        for(auto it : m)
        {
            cout << it.first << " " << it.second << endl;
        }

        // With iterator
        unordered_map <string, int> :: iterator i = m.begin();

        while(i != m.end())
        {
            cout << i -> first << " " << i -> second << endl;
            i++;
        }

        
    return 0;
}
