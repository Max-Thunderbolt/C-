#include <iostream>
#include "Calendar.h"
#include "Utils.h"
#include "Event.h"

using namespace std;

int main()
{
    Calendar *c = new Calendar(get_api_results(4, 10));
    cout << c;
    string *x;
    string y = "Semester Test";
    x = &y;
    long int *intPt;
    long int f = 1670750784;
    intPt = &f;
    long int *intPt2;
    long int g = 2000000000;
    intPt2 = &g;
    int *temp= new int(4);
    cout << "\nfiltering: \n";
    vector<Event> filter = c->filterEvents(temp, intPt, intPt2, x);
    for (int i = 0; i < filter.size(); i++)
    {
        cout << filter[i] << endl;
        cout << "id:  " << filter[i].id << endl;
    }

    cout << "\n upComing: \n";
    Event *up = c->getUpcommingEvent(1670750784);
    if (up)
    {
        cout << *up << endl;
    }
    else
    {
        cout<<"niks";
    }

    cout << "\n altering: \n";
    y = "ahhhhhhhhh";
    x = &y;
    f = 16707507878784;
    intPt = &f;
    c->alterEvent(544, intPt, x);
    cout << c;

    cout << "\n removing: \n";
    c->removeEvent(544);
    cout << c;
    cout << "\n first even: \n";
    cout << *c->getFirstEvent();
    return 0;
}