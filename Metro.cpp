#include <iostream>
#include <climits>
#define PI 3.14
using namespace std;


int minDistance(int distance[], bool stat[])
{
    int minimum = INT_MAX, index;
    for (int k = 0; k <= 29; k++)
    {
        if (stat[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            index = k;
        }
    }
    return index;
}

void dijkstra(int graph[30][30], int source, string stations[30])
{
    int distance[30];
    bool stat[30];
    for (int k = 0; k <= 29; k++)
    {
        distance[k] = INT_MAX;
        stat[k] = false;
    }
    distance[source] = 0;

    for (int k = 0; k <= 29; k++)
    {
        int m = minDistance(distance, stat);
        stat[m] = true;
        for (int i = 0; i <= 29; i++)
        {
            if (!stat[i] && graph[m][i] && distance[m] != INT_MAX && distance[m] + graph[m][i] < distance[i])
                distance[i] = distance[m] + graph[m][i];
        }
    }
    cout << "Minimum Number of stations from  " << stations[source] << " to every station  : " << endl;
    for (int k = 0; k <= 29; k++)
    {
        cout<< "Minimum stations from " << stations[source] << " to " << stations[k] << " are " << distance[k] << endl;
    }
    int p;
    cin>>p;
}
int main()
{
    coout<<"Testing"<<endl;
    int graph[30][30] = {
        {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        };
    int source;
    string stations[] = {"Trilok Puri", "Mayur Vihar 2", "Mandawali West", "IP Extenstion", "Karkarduma", "Noida Sec 15", "Noida Sec 16", "Noida Sec 18", "Botanical Gardan", "Noida Sec 52", "Noida Sec 34", "Mayur Vihar Extention", "Mayur Vihar 1",
                           "Akshardham", "Laxmi Nagar", "Golf Course", "Noida City Centre ", "Yamuna Bank", "Nirman Vihar", "Preet Vihar", "Vaishali", "Kaushami", "Anand Vihar", "MayaPuri", "Naraina Vihar", "Delhi Cantt", "Dhola Kuan", "Bhikoji Coma Place", "Sarojani Nagar", "Dilli Hat", "South Extention"};

    for (int i = 0; i <= 29; i++)
        cout << "Enter " << i << " for " << stations[i] << endl;
    cout << "Enter source station: ";
    cin >> source;
    dijkstra(graph, source, stations);
    cout << endl;
    return 0;
}


//Login system
/*
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

class Person
{
private:
    string name;
    string userName;
    string password;

public:
    bool login();
    void registration();
    void forgetPassword();
};
bool Person::login()
{
    int count = 0;
    int isUserNameMatch=0;
    string UName, pass;
    cout << "Enter the user name : " << endl;
    cin >> UName;
    cout << "Enter the Password : " << endl;
    cin >> pass;
    fstream check;
    check.open("DataBase.txt", ios::in | ios::binary);
    check.read((char *)this, sizeof(*this));
    while (!check.eof())
    {
        
        if (this->userName == UName)
        {
            if(this->password==pass)
            {
                cout << "\nLogin Sucessfully "<<endl<<endl<<endl;
                count++;
                return true;
            }
            else
            {
                isUserNameMatch++;
            }
        }
        check.read((char *)this, sizeof(*this));
    }

    if(isUserNameMatch==1)
        cout<<"\n'UserName is Right but Password is wrong '";
    if (count == 0)
        cout << "\n'Informations Don't match'"<<endl<<endl<<endl;
    return false;
    check.close();
}
void Person::registration()
{
    cout << "WELCOME" << endl;
    cout << "Enter Your Name : ";
    cin >> this->name;
    cout << "Enter the User Id : ";
    cin >> this->userName;
    cout << "Enter the Password : ";
    cin >> this->password;
    fstream insert;
    insert.open("DataBase.txt", ios::app | ios::binary);
    insert.write((char *)this, sizeof(*this));
    insert.close();
}
void Person::forgetPassword()
{
    int count=0;
    string UName;
    cout<<"Enter the User Name : ";
    cin>>UName;
    fstream find;
    find.open("DataBase.txt",ios::in|ios::binary);
    find.read((char*)this,sizeof(*this));
    while(!find.eof())
    {
        if(this->userName==UName)
        {
            cout<<"Your Password is : "<<password<<endl;
            count++;
            break;
        }
        find.read((char*)this,sizeof(*this));
        find.close();
    }
    if(count==0)
        cout<<"\nUser Name not found "<<endl;
}
void menu()
{
    bool flag = true;
    while (flag)
    {
        Person P;
        cout << "Press 1 for login : " << endl;
        cout << "Press 2 for registration : " << endl;
        cout << "Press 3 for recover password : " << endl;
        cout << "Press 4 for EXIT : " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            P.login();
            break;
        case 2:
            P.registration();
            break;
        case 3:
            P.forgetPassword();
            break;
        case 4:
            flag = false;
            break;
        default:
            cout << "INVALID CHOICE";
            break;
        }
    }
    cout << "THANKYOU" << endl;

}
int main()
{
    menu();
    return 0;
}








*/






/*
int minDistance(int distance[], bool stat[])
{
    int minimum = INT_MAX, index;
    for (int k = 0; k <= 52; k++)
    {
        if (stat[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            index = k;
        }
    }
    return index;
}




class implementation
{
    public:

    vector<int>dijkstra(vector<vector<int>>&vec, int vertices, int edges, int source)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < edges; i++)
        {
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        vector<int> distance(vertices);
        for (int i = 0; i < vertices; i++)
        {
            distance[i] = INT_MAX;
        }

        set<pair<int, int>> st;
        distance[source] = 0;
        st.insert(make_pair(0, source));
        while (!st.empty())
        {
            // fetch top record
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            // remove top record now
            st.erase(st.begin());

            // traverse on neighbour

            for (auto neighbour : adj[topNode])
            {
                if (nodeDistance + neighbour.second < distance[neighbour.first])
                {
                    auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    // distance update
                    distance[neighbour.first] = nodeDistance + neighbour.second;
                    // record push in set
                    st.insert(make_pair(distance[neighbour.first], neighbour.first));
                }
            }
        }
        return distance;
    }
};

int main()
{
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        unordered_map<int, list<pair<int, int>>> adj;
        adj[0].push_back(make_pair(3,5));
        adj[0].push_back(make_pair(4,7));
        adj[1].push_back(make_pair(2,3));
        adj[1].push_back(make_pair(4,2));
        adj[2].push_back(make_pair(3,3));
        implementation obj;
        vector<int>dis=obj.dijkstra(adj,5,5,0);
        for (int i = 0; i < 5; i++)
        {
            cout<<dis[i]<<"  ";
        }
        

    return 0;
}
*/