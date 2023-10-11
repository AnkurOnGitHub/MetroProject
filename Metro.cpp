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
    cout<<"Testing"<<endl;
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
