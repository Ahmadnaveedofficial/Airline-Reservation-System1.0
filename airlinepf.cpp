#include<iostream>
#include<fstream> 
#include<string>  
#include <time.h>  
using namespace std;

void inputCustomerDetails(int* customerId,string* name,int* age,string* gender,string* address,string* phone)
 {
   system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t<--------------- CUSTOMER DETAILS FORM --------------->\n\n";
    cout<<"\t\t\t\t\t\t\tEnter Customer ID: ";
    cin>>*customerId;
    cin.ignore();
    cout<<"\t\t\t\t\t\t\tEnter Name: ";
    getline(cin,*name);
    cout<<"\t\t\t\t\t\t\tEnter Age: ";
    cin>>*age;
    cin.ignore();
    cout<<"\t\t\t\t\t\t\tEnter Gender: ";
    getline(cin,*gender);
    cout<<"\t\t\t\t\t\t\tEnter Address: ";
    getline(cin,*address);
    cout<<"\t\t\t\t\t\t\tEnter Phone Number: ";
    getline(cin,*phone);
    cout<<"\n";
    cout<<"\t\t\t\t\t\t\tCustomer details saved successfully!"<<endl;
    cout<<"\n\n";
    system("pause");
}

void printTicket(int* customerId,const string* name,const string* gender,const string* flightNumber, 
const string* destination,const string* departureTime,const string* duration,float* price,string* seatNumber) 
{

  system("cls");
    ofstream outf("ticket.txt",ios::app);
    if (outf.is_open())
	 {
        outf<<"<------------ Airline Ticket ------------>\n";
        outf<<"Customer ID:    \t"<<*customerId<<endl;
        outf<<"Customer Name:  \t"<<*name<<endl;
        outf<<"Customer Gender:\t"<<*gender<<endl;
        outf<<"Flight Number:  \t"<<*flightNumber<<endl;
        outf<<"Seat No:        \t"<<*seatNumber<<endl;
        outf<<"Destination:    \t"<<*destination<<endl;
        outf<<"Departure Time: \t"<<*departureTime<<endl;
        outf<<"Duration:       \t"<<*duration<<" hours" <<endl;
        outf<<"Price:          \t Rs."<<*price<<endl;
        
    }
    outf.close();
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\tTicket has been printed! Check 'ticket.txt'.\n";
}

void displayTicket(int*customerId,const string* name,const string* gender,const string* flightNumber, 
const string* destination,const string* departureTime,const string* duration,float* price,string* seatNumber)
 {

    system("cls");
	cout<<"\n\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t\t\t\t <------------ Airline Ticket ------------>\n";
    cout<<"\t\t\t\t\t\t\t Customer ID:        "<<*customerId<<endl;
    cout<<"\t\t\t\t\t\t\t Customer Name:     "<<*name<<endl;
    cout<<"\t\t\t\t\t\t\t Customer Gender:    "<<*gender<<endl;
    cout<<"\t\t\t\t\t\t\t Flight Number:      "<<*flightNumber<<endl;
    cout<<"\t\t\t\t\t\t\t Seat No:             "<<*seatNumber<<endl;
    cout<<"\t\t\t\t\t\t\t Destination:        "<<*destination<<endl;
    cout<<"\t\t\t\t\t\t\t Departure Time:     "<<*departureTime<<endl;
    cout<<"\t\t\t\t\t\t\t Duration:           "<<*duration<<" hours"<<endl;
    cout<<"\t\t\t\t\t\t\t Price:             Rs."<<*price<<endl;
  
}


void bookAndAddDetails(int* customerId,string* name,int* age,string* gender,string* address,string* phone,
 string flights[][5],int flightCount,bool* flightBooked,string* selectedFlightNumber, 
 string* selectedDestination,string* selectedDepartureTime,string* selectedDuration,float* selectedPrice,string* seatNumber) 
{
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tAvailable Flights\n\n";
    cout<<"\t\t\t\t\t\tFlight No\tDestination\t  Departure\t\tDuration\tPrice\n";

    for (int i=0;i<flightCount;++i)
	 {
        cout<<"\t\t\t\t\t\t"<<flights[i][0]<<"  \t"<<flights[i][1]<<"\t\t"<<flights[i][2]<< "\t"<<flights[i][3]<<" hours\t"<<"Rs."<<flights[i][4]<<endl;
     }

    cout<<"\n\n\t\t\t\t\t\t\tSelect a flight by entering the flight number: ";
    cin>>*selectedFlightNumber;

    bool flightFound = false;
    for (int i=0; i<flightCount;++i) 
	{
        if(flights[i][0]==*selectedFlightNumber)
		 {
            *selectedDestination=flights[i][1];
            *selectedDepartureTime=flights[i][2];
            *selectedDuration=flights[i][3];
            *selectedPrice=stof(flights[i][4]);
            flightFound=true;
            *flightBooked=true;
                 // Generate a random seat number (Row: 1–30, Column: A–F)
            srand(time(0));
            int row = rand() % 30 + 1;
            char column = 'A' + (rand() % 6); 
            *seatNumber = to_string(row) + column; 
            break;
        }
    }

    if (flightFound)
	 {
        inputCustomerDetails(customerId,name,age,gender,address,phone);
        cout<<"\n\t\t\t\t\t\t\tFlight booked successfully!\n";
        displayTicket(customerId,name,gender,selectedFlightNumber,selectedDestination,selectedDepartureTime,selectedDuration,selectedPrice,seatNumber);
    } 
	else 
	{
       cout<<"\n\n\t\t\t\t\t\t\tInvalid flight number! Please try again.\n";
    }
    system("pause");
  }

void aboutUs()
 {
    system("cls");
    cout<<"\n\n\n\n\n\n\n"
     <<"\t\t\t\t\t<-------------------------------- About Us ------------------------------->\n"
     <<"\n\t\t\t\t\tWelcome to Hazel Blue Airline where we believe that every journey is more\n"
     <<"\t\t\t\t\tthan just reaching a destination. Your safety, connection, and comfort\n"
     <<"\t\t\t\t\tare our priorities. We believe that aviation is proof that with\n"
     <<"\t\t\t\t\tdetermination, we have the capacity to achieve the impossible.\n"
     <<"\n\t\t\t\t\tThis airline was founded by four members whose names are given below:\n"
     <<"\t\t\t\t\tAhmad, Saqib, Unbreen, and Ukasha, with a passion for aviation and excellence.\n"
     <<"\t\t\t\t\tTogether, we navigate the skies with ease and comfort, creating unforgettable\n"
     <<"\t\t\t\t\tjourneys with you.\n"
     <<"\n\t\t\t\t\t<------------------------------------------------------------------------>\n";
       system("pause");
    }

int main() 
{
  system("color F0");
    int choice;
    int customerId,age; 
    string name,gender,address,phone;
    string flights[6][5]={
        {"Pk-498", "Dubai", "08-12-2024 7:40PM", "04", "14000"},
        {"Pk-198", "Canada", "22-01-2024 5:40AM", "16", "34000"},
        {"Pk-798", "UK", "09-12-2024 7:40PM", "14", "44000"},
        {"Pk-578", "USA", "25-02-2024 5:40AM", "18", "94000"},
        {"Pk-898", "Bali", "22-01-2024 5:40AM", "16", "64000"},
        {"Pk-348", "Europe", "22-01-2024 5:40AM", "07", "78000"}
    };          
    
    int flightCount = 6;
    string selectedFlightNumber,selectedDestination,selectedDepartureTime,selectedDuration,seatNumber;
    float selectedPrice;
    bool flightBooked = false;
    
    do
	 {
        system("cls");
        cout<<"\n\n\n\n\n\n\n "<<endl;
        cout<<"\t\t\t\t\t\t\t<---------- WELCOME TO OUR HAZEL BLUE AIRLINE ---------->\n"<<endl;
        cout<<"\t\t\t\t\t\t\t\t        [1] Book a Flight                      "<<endl;
        cout<<"\t\t\t\t\t\t\t\t        [2] Print Ticket                       "<<endl;
        cout<<"\t\t\t\t\t\t\t\t        [3] What We Are?                       "<<endl;
        cout<<"\t\t\t\t\t\t\t\t        [4] Exit                               "<<endl;
        cout<<"\n\n\n";
        cout<<"\t\t\t\tEnter your choice: ";
        cin>>choice;
        cout<<"\n";
        switch(choice) 
		{
            case 1:
			{
				 bookAndAddDetails(&customerId,&name,&age,&gender,&address,&phone,flights,flightCount, 
				 &flightBooked,&selectedFlightNumber,&selectedDestination,&selectedDepartureTime,&selectedDuration,&selectedPrice,&seatNumber);
                break;
			}
			
            case 2:
			{
            	system("cls");
				if(flightBooked) 
				{
                    printTicket(&customerId,&name,&gender,&selectedFlightNumber,&selectedDestination,
					&selectedDepartureTime,&selectedDuration,&selectedPrice,&seatNumber);
                } 
				else 
				{
                    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo ticket has been booked yet.\n";
                }
                system("pause");
                break;
			}
                
                case 3:
       	         {
       		        aboutUs();
            	     break;
				}
            case 4:
            	{
            		system("cls");
            	 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tThank you for using Hazel Blue Airline!\n";
                break;
				} 
            default:
                 {
                 	system("cls");
        	    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tInvalid choice! Please try again.\n";
	          	}
                system("pause");
        }
    } 
	while (choice != 4);
    return 0;
}
