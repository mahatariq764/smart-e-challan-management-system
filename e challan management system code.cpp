#include <iostream>
using namespace std;
class owner {
public:
    string name;
    string cnic;
    void registerowner() {
        try {
            cout<<"Enter owner Name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter CNIC with dashes (15 digits): ";
            cin>>cnic;
            if (cnic.length() != 15) {
                throw cnic;
            }
            cout<<"Owner registered successfully"<<endl;
        }
        catch (string invalidcnic) {
            cout<<"Exception: Invalid CNIC "<<invalidcnic<<endl;
        }
    }
    void showowner() {
        cout<<"Owner Name: "<<name<<endl;
        cout<<"Owner CNIC: "<<cnic<<endl;
    }
};
class vehicle {
public:
    string model;
    string regletters;
    string regno;
    virtual void registervehicle() = 0; 
    virtual void showvehicle() {
        cout<<"Model: "<<model<<endl;
        cout<<"Registration: "<<regletters<< "-"<<regno<<endl;
    }
    virtual string gettype() = 0; 
};
class car : public vehicle {
public:
    void registervehicle() {
        cin.ignore();
        cout<<"Enter Car Model: ";
        getline(cin, model);
        cout<<"Enter registration letters (Capital): ";
        cin>>regletters;
        cout<<"Enter registration number (4 digits): ";
        cin>>regno;
        if (regno.length() != 4) 
		throw regno;
        cout<<"Car registered successfully"<<endl;
    }
    string gettype() override { 
	      return "Car"; 
	}
};
class bike : public vehicle {
public:
    void registervehicle()  {
        cin.ignore();
        cout<<"Enter Bike Model: ";
        getline(cin, model);
        cout<<"Enter registration letters (Capital): ";
        cin>>regletters;
        cout<<"Enter registration number (4 digits): ";
        cin>>regno;
        if (regno.length() != 4) 
		throw regno;
        cout<<"Bike registered successfully"<<endl;
    }
    string gettype() override { 
	          return "Bike";
	 }
};
class truck : public vehicle {
public:
    void registervehicle()  {
        cin.ignore();
        cout<<"Enter Truck Model: ";
        getline(cin, model);
        cout<<"Enter registration letters (Capital): ";
        cin>>regletters;
        cout<<"Enter registration number (4 digits): ";
        cin>>regno;
        if (regno.length() != 4) 
		throw regno;
        cout<<"Truck registered successfully"<<endl;
    }
    string gettype() override {
	       return "Truck"; 
	 }
};
class rikshaw : public vehicle {
public:
    void registervehicle()  {
        cin.ignore();
        cout<<"Enter rickshaw model: ";
        getline(cin, model);
        cout<<"Enter registration letters (Capital): ";
        cin>>regletters;
        cout<<"Enter registration number (4 digits): ";
        cin>>regno;
        if (regno.length() != 4) 
		throw regno;
        cout<<"Rickshaw registered successfully"<<endl;
    }
    string gettype() override { 
	return "Rickshaw";
	 }
};
class payment {
public:
    bool paid = false;
    void pay(int fine) {
        try {
            if (paid) {
                cout<<"Challan already paid"<<endl;
                return;
            }
            int choice;
            cout<<"Pay Fine "<<fine<<endl;
            cout<<"1. Cash"<<endl;
            cout<<"2. Card"<<endl;
            cout<<"Choice: ";
            cin>>choice;
            if (choice == 1) {
                paid = true;
                cout<<"Payment Successful in Cash"<<endl;
				cout<<endl;
            }
            else if (choice == 2) {
                cin.ignore();
                string bankname, cardno;
                cout<<"Enter Bank Name: ";
                getline(cin, bankname);
                cout<<"Enter Card Number (12-16 digits): ";
                getline(cin, cardno);
                if (cardno.length() < 12 || cardno.length() > 16) {
                    throw cardno;
                }
                paid = true;
                cout<<"Payment successful via Card"<<endl;
                cout<<"Bank: "<<bankname<<endl;
                cout<<"Card Number: "<<cardno<<endl; 
				cout<<endl;
            }
            else {
                throw choice;
            }
        }
        catch (string invalidcard) {
            cout<<"Exception: invalid card number "<<invalidcard<<endl;
        }
        catch (int) {
            cout<<"Exception: invalid payment option"<<endl;
        }
    }
};
class challan {
public:
    int challanid = 0;
    int fine = 0;
    string violationtype;
    payment p;
    void generate(owner &o, vehicle &v) {
        challanid = 1;
        string vtype = v.gettype();
        if (vtype == "Car") {
            violationtype = "Seatbelt Violation";
            fine = 2000;
        }
        else if (vtype == "Bike") {
            violationtype = "No Helmet";
            fine = 1000;
        }
        else if (vtype == "Truck") {
            violationtype = "Over Speeding";
            fine = 2500;
        }
        else if (vtype == "Rickshaw") {
            violationtype = "Wrong Turn";
            fine = 500;
        }
        cout<<endl;
        cout<<"E-challan:"<<endl;
        cout<<"Challan ID: "<<challanid<<endl;
        o.showowner();
        v.showvehicle();
        cout<<"Violation: "<<violationtype<<endl;
        cout<<"Fine amount: "<<fine<<endl;
        cout<<"Status: Unpaid"<<endl<<endl; 
    }
    void pay() {
        try {
            if (challanid == 0) {
                throw challanid;
            }
            p.pay(fine);
        }
        catch (int) {
            cout<<"Exception: No challan generated yet"<<endl;
        }
    }
    void history() {
        if (challanid == 0) {
            cout<<"No challan history"<<endl;
            return;
        }
        cout<<"challan history: "<<endl;
        cout<<"Challan ID: "<<challanid<<endl;
        cout<<"Violation: "<<violationtype<<endl;
        cout<<"Fine: "<<fine<<endl;
        cout<<"Status: "<<(p.paid ? "Paid" : "Unpaid")<<endl;
		cout<<endl;
    }
};
int main() {
    owner o;
    challan ch;
    int choice, vchoice = 0;
    car c;
    bike b;
    truck t;
    rikshaw r;
    do {
        cout<<"E-challan management system"<<endl;
        cout<<"1. Register owner"<<endl;
        cout<<"2. Register vehicle"<<endl;
        cout<<"3. Generate challan"<<endl;
        cout<<"4. Pay challan"<<endl;
        cout<<"5. View history"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice) {
        case 1:
            o.registerowner();
            break;
        case 2:
            cout<<endl;
            cout<<"1. Car"<<endl;
            cout<<"2. Bike"<<endl;
            cout<<"3. Truck"<<endl;
            cout<<"4. Rickshaw"<<endl;
            cout<<"Choice: ";
            cin>>vchoice;
            try {
                if (vchoice == 1) 
				c.registervehicle();
                else if (vchoice == 2) 
				b.registervehicle();
                else if (vchoice == 3) 
				t.registervehicle();
                else if (vchoice == 4) 
				r.registervehicle();
                else 
				cout<<"Invalid vehicle choice"<<endl;
            } catch (string invalidreg) {
                cout<<"Exception: Invalid registration number"<<endl;
            }
            break;
        case 3:
            if (vchoice == 0) {
                cout<<"Register vehicle first"<<endl;
            } 
			else {
                if (vchoice == 1) 
				ch.generate(o, c);
                else if (vchoice == 2) 
				ch.generate(o, b);
                else if (vchoice == 3) 
				ch.generate(o, t);
                else if (vchoice == 4) 
				ch.generate(o, r);
            }
            break;
        case 4:
            ch.pay();
            break;
        case 5:
            ch.history();
            break;
        case 6:
            cout<<"Program exit"<<endl;
            break;
        default:
            cout<<"Invalid"<<endl;
        }
        cout<<endl;
    } while (choice != 6);
    return 0;
}
