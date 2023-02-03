#include <iostream>
#include <vector>
#include <string>
#include <map>

const int COST_STANDARD = 100000; // VND/day
const int COST_LUXURY = 120000; // VND/day
const int COST_FAN = 50000; // VND/day
int count=0;


struct Booth 
{
  int code;
  int area;
  std::string location;
  int type; // 0: standard, 1: luxury
  int fans; // only applicable to luxury booths
  int tables; // only applicable to luxury booths
  int chairs; // only applicable to luxury booths
  std::string roofMaterial; // only applicable to standard booths
  std::string partitionMaterial; // only applicable to standard booths
  void input_booth()
    {
      std::cout << "Booth's code: ";
      std::cin >> code;
      std::cout>>"Booth's area: ";
      std::cin >> area;
      std:: cin.ignore();
      std::cout << "Booth's location: ";
      getline(std:: cin, location);
      std:: cin.ignore();
    }
};

struct Order {
  std::string name;
  std::string address;
  int startTime; // UNIX timestamp
  int endTime; //UNIX timestamp
  int boothCode;
  int deposit;
  void input_order_management()
  {    std:: cin.ignore();
      std::cout <<"Order's name: ";
      std:: cin.ignore();      
      getline(std::cin, name);
      std::cout <<" Order's address: ";
      getline(std::cin, address);
      std:: cin.ignore();
      std::cout <<" StarTime: ";
      std::cin >> startTime;
      std::cout <<"EndTime: ";
      std::cin >> endTime;
      std::cout <<"BoothCode: ";
      std::cin >>boothCode;
      std::cout <<"Deposit: ";
      std::cin >> deposit;
  }

};

class ExhibitionArea {
  public:
    ExhibitionArea() {
      this->numRented = 0;
    }

    // Add a booth to the showroom
    void addBooth(Booth booth) {
      this->booths.push_back(booth);
    }

    // Edit an existing booth in the showroom
    void editBooth(int code, Booth newBooth) {
      for (int i = 0; i < this->booths.size(); i++) {
        if (this->booths[i].code == code) {
          this->booths[i] = newBooth;
          break;
        }
      }
    }

    // Delete a booth from the showroom
    void deleteBooth(int code) {
      for (int i = 0; i < this->booths.size(); i++) {
        if (this->booths[i].code == code) {
          this->booths.erase(this->booths.begin() + i);
          break;
        }
      }
    }

    // Place a tenant order for a booth
    void placeOrder(Order order) {
      this->numRented++;
      this->orders.push_back(order);
    }

    // Get the number of rented booths
    int getNumRented() {
      return this->numRented;
    }

    // Search a booth by code and display full information
    void lookupBooth(int code) {
      for (int i = 0; i < this->booths.size(); i++) {
        if (this->booths[i].code == code) {
          std::cout << "Booth code: " << this->booths[i].code << std::endl;
          std::cout << "Area: " << this->booths[i].area << " m^2" << std::endl;
          std::cout << "Location: " << this->booths[i].location << std::endl;
          if (this->booths[i].type == 0) {
            std::cout << "Type: standard" << std::endl;
            std::cout << "Roof material: " << this->booths[
            
            
    int calculateRentalCost(Order order) {
        int index = boothMap[order.boothCode];
        Booth booth = booths[index];
        if (booth.type == 0) {
            return booth.area * 100000 * (order.endTime - order.startTime);
        } else {
            return booth.area * 120000 * (order.endTime - order.startTime) + booth.numFans * 50000 * (order.endTime - order.startTime);
        }
    }

    int calculateRevenue(int startTime, int endTime) {
        int revenue = 0;
        for (Order order : orders) {
            if (order.startTime >= startTime && order.endTime <= endTime) {
                revenue += calculateRentalCost(order);
            }
        }
        return revenue;
    }

    void updateRentalCost(int newCost) {
        for (Booth& booth : booths) {
            if (booth.type == 0) {
                booth.area = newCost;
            }
        }
    }

    void updateFanCost(int newCost) {
        for (Booth& booth : booths) {
            if (booth.type == 1) {
                booth.numFans = newCost;
            }
        }
    }
}
void printMenu() {
	std::cout << "\t\t EXHIBITION AREA MANAGEMENT SYSTEM\n";
	std::cout << "\tPlease choose an option below:\n";
	std::cout << "\t1. Add a booth\n";
	std::cout << "\t2. Edit a booth\n";
	std::cout << "\t3. Remove a booth\n";
	std::cout << "\t4. List of current rental booths \n";
	std::cout << "\t5. Search booth by code and display full information \n";
	std::cout << "\t6. Revenue by time \n";
	std::cout << "\t7. Update price\n";
	std::cout << "\t8. Print specific booth\n";
	std::cout << "\t9. Print all  booth\n";
	std::cout << "\t10. Exit program\n";
	std::cout << "\n\t-> Your option: "; 
}

void Press()
{
    system("pause");
    system("cls");
}

int option;
    /* EXHIBITION AREA MANAGEMENT SYSTEM  */
    while (true) {
        cout << endl;
        printMenu();
        cin >> option;  // User input wrong data
        if (!cin) {
            // user didn't input a number
            cin.clear();                      // reset failbit
            cin.ignore(MAX_STREAMSIZE, '\n'); // skip bad input
        }

        switch (option) {
            case 1: // Add a booth
                inputFormList(List);
                break;

            case 2: // Edit a booth
                editFormList(List);
                break;

            case 3: // Remove a booth 
                removeFormList(List);
                break;

            case 4: // List of current rental booths 
                searchFormList(List);
                break;
                
            case 5: // Search booth by code and display full information
                listCompletedFileByTime(List);
                break;
            
            case 6: // Revenue by time
                updatePrice();
                
                break;

            case 7: //Update price
                printRevenue(List);
                break;

            case 8: // Print specific form
                printSpecificForm(List);
                break;

            case 9: // Print all forms
                printFormList(List);
                break;

            case 10: // Exit program
                List.FormList.clear();
                exit(1);
                break;

            default:
                cout << "This feature is currently not available\n";   
                break;
        }
    }
    
}