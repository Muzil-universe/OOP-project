#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

// Service Interface (Abstract Class)
class Service {
public:
    virtual ~Service() {}
    virtual string getServiceName() const = 0;
    virtual double getServiceCharge() const = 0;
    virtual void displayServiceInfo() const {
        cout << "Service: " << getServiceName() << " | Charge: $" << getServiceCharge() << endl;
    }
};

// Derived Service Classes
class LaundryService : public Service {
private:
    string serviceType; // "Standard", "Express", "Dry Clean"
    double baseCharge;
    int itemCount;

public:
    LaundryService(string type = "Standard", double charge = 15.0, int items = 1)
        : serviceType(type), baseCharge(charge), itemCount(items) {}

    string getServiceName() const override {
        return "Laundry Service (" + serviceType + ")";
    }

    double getServiceCharge() const override {
        return baseCharge * itemCount;
    }

    void setItemCount(int items) { itemCount = items; }
    int getItemCount() const { return itemCount; }
};

class MealService : public Service {
private:
    string mealType; // "Breakfast", "Lunch", "Dinner", "Room Service"
    double pricePerMeal;
    int numberOfMeals;

public:
    MealService(string type = "Breakfast", double price = 25.0, int meals = 1)
        : mealType(type), pricePerMeal(price), numberOfMeals(meals) {}

    string getServiceName() const override {
        return "Meal Service (" + mealType + ")";
    }

    double getServiceCharge() const override {
        return pricePerMeal * numberOfMeals;
    }

    void setNumberOfMeals(int meals) { numberOfMeals = meals; }
    int getNumberOfMeals() const { return numberOfMeals; }
};

class TransportService : public Service {
private:
    string transportType; // "Airport Pickup", "City Tour", "Taxi Service"
    double baseFare;
    double distanceKm;
    double ratePerKm;

public:
    TransportService(string type = "Airport Pickup", double fare = 50.0, double distance = 0.0, double rate = 2.0)
        : transportType(type), baseFare(fare), distanceKm(distance), ratePerKm(rate) {}

    string getServiceName() const override {
        return "Transport Service (" + transportType + ")";
    }

    double getServiceCharge() const override {
        return baseFare + (distanceKm * ratePerKm);
    }

    void setDistance(double distance) { distanceKm = distance; }
    double getDistance() const { return distanceKm; }
};

class Room{
    private:
    int roomNumber;
    string type;
    double pricePerDay;
    bool isavailable;
    vector <string> feature;
    public:
Room(int number, string t, double price)
       {
        roomNumber = number;
        type = t;
        pricePerDay = price;
        isavailable = true;
       }
        void addFeature(const string& f) {
        feature.push_back(f);
    }

    vector<string> getFeatures() const {
        return feature;
    }

        virtual ~Room() {}


    virtual double calculateBill(int days) const = 0;
    virtual void displayInfo() const = 0;
    void bookRoom(){
        isavailable = false;
        cout << "Room booked successfully." << endl;
    }
    void vacateRoom(){
        isavailable = true;
        cout << "Room vacated successfully." << endl;
    }
    bool isRoomAvailable() const {
        return isavailable;
    }


     int getRoomNumber() const {
        return roomNumber;
    }
void setPricePerDay(double newPrice) {
    pricePerDay = newPrice;
}

    double getPricePerDay() const {
        return pricePerDay;
    }

    string getRoomType() const {
        return type;
    }



};

class StandardRoom : public Room {
private:
    double serviceFee;
public:
    StandardRoom(int number, double price, double service = 20.0)
        : Room(number, "Standard", price), serviceFee(service) {}

    double calculateBill(int days) const override {
        return (getPricePerDay() * days) + serviceFee;
    }

    void displayInfo() const override {
        cout << "Room #" << getRoomNumber() << " | Type: " << getRoomType()
             << " | Price: $" << getPricePerDay() << "/day"
             << " | Service Fee: $" << serviceFee
             << " | Available: " << (isRoomAvailable() ? "Yes" : "No") << endl;

        cout << "  Features: ";
        for (const auto& feature : getFeatures()) cout << feature << ", ";
        cout << "\n";
    }
};

class DeluxeRoom:public Room {
    private:
    double serviceFee;
    double luxuryTax;
    vector<string> complementaryItems;
    public:
    DeluxeRoom(int number,  double price, double service, double tax)
        : Room(number,"Deluxe", price){
        serviceFee = service;
        luxuryTax = tax;
        }
    void addComplementaryItem(const string& item) {
        complementaryItems.push_back(item);
    }
    vector<string> getComplementaryItems() const {
        return complementaryItems;
    }
    double calculateBill(int days) const override {
        return (getPricePerDay() * days) + serviceFee + luxuryTax;
    }
  void displayInfo() const override {
    cout << "Room #" << getRoomNumber() << " | Type: " << getRoomType()
         << " | Price: $" << getPricePerDay() << "/day"
         << " | Service Fee: $" << serviceFee
         << " | Tax: $" << luxuryTax
         << " | Available: " << (isRoomAvailable() ? "Yes" : "No") << endl;

    cout << "  Features: ";
    for (const auto& feature : getFeatures()) cout << feature << ", ";
    cout << "\n  Complimentary: ";
    for (const auto& item : complementaryItems) cout << item << ", ";
    cout << "\n";
}


};

class SuiteRoom:public Room {
    private:
    double serviceFee;
    double luxuryTax;
    vector<string> complementaryItems;
    public:
    SuiteRoom(int number,  double price, double service, double tax)
        : Room(number,"Suite", price){
        serviceFee = service;
        luxuryTax = tax;
        }
    void addComplementaryItem(const string& item) {
        complementaryItems.push_back(item);
    }
    vector<string> getComplementaryItems() const {
        return complementaryItems;
    }
    double calculateBill(int days) const override {
        return (getPricePerDay() * days) + serviceFee + luxuryTax;
    }
    void displayInfo() const override {
    cout << "Room #" << getRoomNumber() << " | Type: " << getRoomType()
         << " | Price: $" << getPricePerDay() << "/day"
         << " | Service Fee: $" << serviceFee
         << " | Tax: $" << luxuryTax
         << " | Available: " << (isRoomAvailable() ? "Yes" : "No") << endl;

    cout << "  Features: ";
    for (const auto& feature : getFeatures()) cout << feature << ", ";
    cout << "\n  Complimentary: ";
    for (const auto& item : complementaryItems) cout << item << ", ";
    cout << "\n";
}


};

class customer{
    private:
    string name;
    string contact;
    string idNumber;
    int bookedRoomNumber;
    int daysOfStay;
    string checkInDate;
    string checkOutDate;
    int loyaltyPoints;
    vector<Service*> additionalServices; // Composition with services

    public:

    customer()
        : name(""), contact(""), idNumber(""), bookedRoomNumber(0), daysOfStay(0), checkInDate(""), checkOutDate(""), loyaltyPoints(0) {}

    customer(string n, string c, string id, int bookedRoom, int days, const string& checkIn, const string& checkOut)
       {
        name = n;
        contact = c;
        idNumber = id;
        bookedRoomNumber = bookedRoom;
        daysOfStay = days;
        checkInDate = checkIn;
        checkOutDate = checkOut;
        loyaltyPoints = 0;
       }

    // Service management methods
    void addService(Service* service) {
        additionalServices.push_back(service);
        cout << "Service added: " << service->getServiceName() << " ($" << service->getServiceCharge() << ")" << endl;
    }

    void removeService(const string& serviceName) {
        for (auto it = additionalServices.begin(); it != additionalServices.end(); ++it) {
            if ((*it)->getServiceName().find(serviceName) != string::npos) {
                cout << "Service removed: " << (*it)->getServiceName() << endl;
                delete *it;
                additionalServices.erase(it);
                return;
            }
        }
        cout << "Service not found: " << serviceName << endl;
    }

    double calculateServiceCharges() const {
        double total = 0.0;
        for (const Service* service : additionalServices) {
            total += service->getServiceCharge();
        }
        return total;
    }

    void displayServices() const {
        if (additionalServices.empty()) {
            cout << "  No additional services" << endl;
            return;
        }
        cout << "  Additional Services:" << endl;
        for (const Service* service : additionalServices) {
            cout << "    - " << service->getServiceName() << ": $" << service->getServiceCharge() << endl;
        }
    }

    void assignRoom(Room & r, int days) {
        if (r.isRoomAvailable()) {
            bookedRoomNumber = r.getRoomNumber();
            daysOfStay = days;
            r.bookRoom();
            cout << "Room " << bookedRoomNumber << " assigned for " << daysOfStay << " days." << endl;
        } else {
            cout << "Room is not available." << endl;
        }
    }
   void displayCustomerDetails() const {
    cout << "Customer: " << name << " | Contact: " << contact
         << " | ID: " << idNumber << " | Room #: " << bookedRoomNumber
         << " | Stay: " << daysOfStay << " days"
         << " | In: " << checkInDate << " | Out: " << checkOutDate
         << " | Points: " << loyaltyPoints << endl;
    displayServices();
}

    void generateInvoice(const Room & r) const {
        double roomBill = r.calculateBill(daysOfStay);
        double serviceCharges = calculateServiceCharges();
        double totalBill = roomBill + serviceCharges;

        cout << "\n=== INVOICE ===" << endl;
        cout << "Customer: " << name << endl;
        cout << "Room Number: " << bookedRoomNumber << endl;
        cout << "Days of Stay: " << daysOfStay << endl;
        cout << "Room Bill: $" << roomBill << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
        cout << "--------------------------------" << endl;
        cout << "Total Bill: $" << totalBill << endl;
        cout << "===============" << endl;
    }

    void updateLoyaltyPoints() {
        loyaltyPoints += daysOfStay * 10;
        // Bonus points for using services
        loyaltyPoints += additionalServices.size() * 5;
        cout << "Loyalty points updated. Current points: " << loyaltyPoints << endl;
    }

    int getDaysOfStay() const {
        return daysOfStay;
    }
void setDaysOfStay(int days) {
    daysOfStay = days;
}
string checkinDate() const {
        return checkInDate;
    }
   string checkoutDate() const {
        return checkOutDate;
    }
    string getName() const {
        return name;
    }
    string getContact() const {
        return contact;
    }
    string getIdNumber() const {
        return idNumber;
    }
    int getBookedRoomNumber() const {
        return bookedRoomNumber;
    }
    int getLoyaltyPoints() const {
        return loyaltyPoints;
    }

    // Destructor to clean up services
    ~customer() {
        for (Service* service : additionalServices) {
            delete service;
        }
    }
};

class Booking{
    private:
    static int nextBookingID;
    int bookingID;
    customer cust;
    Room  *room;
    string bookingDate;
    string checkOutDate;
    double totalBill;
    string status;

    public:
    Booking( const customer& c, Room* r)
      {
       bookingID = nextBookingID++;

        cust = c;
        room = r;
        bookingDate = c.checkinDate();
        checkOutDate = c.checkoutDate();
        totalBill = 0.0;
        status = "Pending";
      }

     void confirmBooking() {
            room->bookRoom();
            status = "Confirmed";
            int days = cust.getDaysOfStay();
            double roomBill = room->calculateBill(days);
            double serviceCharges = cust.calculateServiceCharges();
            totalBill = roomBill + serviceCharges;

            cout << "Booking confirmed for " << cust.getName() << " in room " << room->getRoomNumber() << endl;
            cout << "Room Bill: $" << roomBill << " | Service Charges: $" << serviceCharges << " | Total: $" << totalBill << endl;
            cout<<"---------------------------------------------------------------------------------------------"<<endl;
    }

    void cancelBooking() {
        room->vacateRoom();
        status = "Cancelled";
        cout << "Booking cancelled for " << cust.getName()  << endl;
    }

    void modifyBookingDetails(int newDays) {
       newDays = newDays + cust.getDaysOfStay();

        // Update customer's days of stay
        cust.setDaysOfStay(newDays);
        cust.updateLoyaltyPoints();

        double roomBill = room->calculateBill(newDays);
        double serviceCharges = cust.calculateServiceCharges();
        totalBill = roomBill + serviceCharges;
        cout << "Booking details modified. New days of stay: " << newDays << ", Total Bill: $" << totalBill << endl;
    }

    void addServiceToBooking(Service* service) {
        cust.addService(service);
        // Recalculate total bill
        double roomBill = room->calculateBill(cust.getDaysOfStay());
        double serviceCharges = cust.calculateServiceCharges();
        totalBill = roomBill + serviceCharges;
        cout << "Total bill updated to: $" << totalBill << endl;
    }

   void displayBookingDetails() const {
    cout << "Booking #" << bookingID << " | Customer: " << cust.getName()
         << " | Room #: " << room->getRoomNumber()
         << " | Booked: " << bookingDate << " to " << checkOutDate
         << " | Bill: $" << totalBill
         << " | Status: " << status << endl;
    cust.displayServices();
}

    customer& getCustomer() { return cust; }
    const customer& getCustomer() const { return cust; }
    string getCustomerName() const { return cust.getName(); }

     string getStatus(){
     return status;
     }

};
int Booking::nextBookingID = 1;

class Hotel {
private:
    vector<Room*> list_of_rooms;
    vector<customer> list_of_customers;
    vector<Booking> list_of_bookings;

public:
    void addRoom(Room* room) {
        list_of_rooms.push_back(room);
        cout << "Room added successfully.\n";
    }

    void listAvailableRooms(string filterByFeature = "") {
        cout << "\nAvailable Rooms:\n";
        cout << string(80, '-') << endl;
        bool found = false;
        for (Room* r : list_of_rooms) {
            if (r->isRoomAvailable()) {
                if (filterByFeature.empty()) {
                    r->displayInfo();
                    found = true;
                } else {
                    for (string feature : r->getFeatures()) {
                        if (feature == filterByFeature) {
                            r->displayInfo();
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        if (!found) {
            cout << "No available rooms found.\n";
        }
        cout << string(80, '-') << endl;
    }

    void bookRoom(customer cust, string roomType) {
        for (Room* r : list_of_rooms) {
            if (r->getRoomType() == roomType && r->isRoomAvailable()) {
                cust.assignRoom( *r, cust.getDaysOfStay());
                Booking booking(cust, r);
                booking.confirmBooking();
                list_of_customers.push_back(cust);
                list_of_bookings.push_back(booking);
                return;
            }
        }
        cout << "No available room found for type: " << roomType << endl;
    }

    void addServiceToCustomer(string customerName, Service* service) {
        for (Booking& booking : list_of_bookings) {
            if (booking.getCustomerName() == customerName && booking.getStatus() == "Confirmed") {
                booking.addServiceToBooking(service);
                return;
            }
        }
        cout << "No active booking found for customer: " << customerName << endl;
    }

    void checkOutCustomer(string customerName) {
        for (Booking& booking : list_of_bookings) {
            if (booking.getCustomerName() == customerName && booking.getStatus() == "Confirmed") {
                // Generate final invoice
                cout << "\n" << string(50, '=') << endl;
                cout << "          CHECKOUT INVOICE" << endl;
                cout << string(50, '=') << endl;
                booking.getCustomer().generateInvoice(*list_of_rooms[0]); // Simplified
                booking.cancelBooking();
                return;
            }
        }
        cout << "No active booking found for customer: " << customerName << endl;
    }

    void generateReport(string reportType) {
        if (reportType == "customers") {
            cout << "\n" << string(80, '=') << endl;
            cout << "                    CUSTOMER REPORT" << endl;
            cout << string(80, '=') << endl;
            for (const customer& cust : list_of_customers) {
                cust.displayCustomerDetails();
                cout << string(80, '-') << endl;
            }
        } else if (reportType == "bookings") {
            cout << "\n" << string(80, '=') << endl;
            cout << "                    BOOKING REPORT" << endl;
            cout << string(80, '=') << endl;
            for (const Booking& b : list_of_bookings) {
                b.displayBookingDetails();
                cout << string(80, '-') << endl;
            }
        } else if (reportType == "rooms") {
            cout << "\n" << string(80, '=') << endl;
            cout << "                     ROOM REPORT" << endl;
            cout << string(80, '=') << endl;
            for (Room* r : list_of_rooms) {
                r->displayInfo();
                cout << string(80, '-') << endl;
            }
        } else {
            cout << "Unknown report type: " << reportType << endl;
        }
    }

    void filterRoomsByPriceRange(double minPrice, double maxPrice) {
        cout << "\nRooms in Price Range [$" << minPrice << " - $" << maxPrice << "]:\n";
        cout << string(80, '-') << endl;
        bool found = false;
        for (Room* room : list_of_rooms) {
            double price = room->getPricePerDay();
            if (price >= minPrice && price <= maxPrice) {
                room->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No rooms found in this price range.\n";
        }
        cout << string(80, '-') << endl;
    }

    void removeRoom(int roomNumber) {
        for (auto it = list_of_rooms.begin(); it != list_of_rooms.end(); ++it) {
            if ((*it)->getRoomNumber() == roomNumber) {
                delete *it;
                list_of_rooms.erase(it);
                cout << "Room " << roomNumber << " removed successfully.\n";
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void modifyRoomPrice(int roomNumber, double newPrice) {
        for (Room* r : list_of_rooms) {
            if (r->getRoomNumber() == roomNumber) {
                r->setPricePerDay(newPrice);
                cout << "Room price updated successfully.\n";
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void generateOccupancyReport() {
        cout << "\n" << string(50, '=') << endl;
        cout << "        OCCUPANCY REPORT" << endl;
        cout << string(50, '=') << endl;
        int totalRooms = list_of_rooms.size();
        int occupiedRooms = 0;

        for (Room* r : list_of_rooms) {
            if (!r->isRoomAvailable()) {
                occupiedRooms++;
            }
        }

        int availableRooms = totalRooms - occupiedRooms;
        double occupancyRate = totalRooms > 0 ? (double)occupiedRooms / totalRooms * 100 : 0;

        cout << "Total Rooms: " << totalRooms << endl;
        cout << "Occupied Rooms: " << occupiedRooms << endl;
        cout << "Available Rooms: " << availableRooms << endl;
        cout << "Occupancy Rate: " << occupancyRate << "%" << endl;
        cout << string(50, '=') << endl;
    }

    bool hasRooms() const {
        return !list_of_rooms.empty();
    }

    // Destructor to clean up dynamically allocated memory
    ~Hotel() {
        for (Room* room : list_of_rooms) {
            delete room;
        }
    }
};

class Admin {
private:
    string username;
    string encryptedPassword;
    int adminLevel;
    Hotel* hotelRef;
    bool isLoggedIn;

    string xorEncryptDecrypt(const string& text, char key = 'K') {
        string result = text;
        for (char& c : result)
            c ^= key;
        return result;
    }

    void loadPasswordFromFile() {
        ifstream file("admin.txt");
        if (file) {
            getline(file, encryptedPassword);
            file.close();
        } else {
            cout << "No admin password found.\nPlease set a new password: ";
            string newPass;
            cin >> newPass;
            encryptedPassword = xorEncryptDecrypt(newPass);
            ofstream outFile("admin.txt");
            outFile << encryptedPassword;
            outFile.close();
            cout << "Password saved.\n";
        }
    }

public:
    Admin(string uname, int level, Hotel* hotel)
        : username(uname), adminLevel(level), hotelRef(hotel), isLoggedIn(false) {
        loadPasswordFromFile();
    }

    bool login() {
        string input;
        cout << "Enter admin password: ";
        cin >> input;

        if (xorEncryptDecrypt(encryptedPassword) == input) {
            isLoggedIn = true;
            cout << "✅ Login successful.\n";
            return true;
        } else {
            cout << "❌ Invalid password.\n";
            return false;
        }
    }

    void logout() {
        isLoggedIn = false;
        cout << "Admin logged out successfully.\n";
    }

    bool isAuthenticated() const {
        return isLoggedIn;
    }

    void addNewRoom(Room* room) {
        if (isLoggedIn)
            hotelRef->addRoom(room);
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void removeRoom(int roomNumber) {
        if (isLoggedIn)
            hotelRef->removeRoom(roomNumber);
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void modifyRoomPrice(int roomNumber, double newPrice) {
        if (isLoggedIn)
            hotelRef->modifyRoomPrice(roomNumber, newPrice);
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void generateOccupancyReport() {
        if (isLoggedIn)
            hotelRef->generateOccupancyReport();
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void generateReport(const string& reportType) {
        if (isLoggedIn)
            hotelRef->generateReport(reportType);
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void listAvailableRooms() {
        if (isLoggedIn)
            hotelRef->listAvailableRooms();
        else
            cout << "🔒 Access denied. Please login first.\n";
    }

    void filterRoomsByPrice(double min, double max) {
        if (isLoggedIn)
            hotelRef->filterRoomsByPriceRange(min, max);
        else
            cout << "🔒 Access denied. Please login first.\n";
    }
};

// Utility functions
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

int getValidInt() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

double getValidDouble() {
    double value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void displayMainMenu() {
    cout << "\n" << string(60, '=') << endl;
    cout << "           🏨 HOTEL MANAGEMENT SYSTEM 🏨" << endl;
    cout << string(60, '=') << endl;
    cout << "1. 👤 Admin Panel" << endl;
    cout << "2. 🛎️  Customer Services" << endl;
    cout << "3. 📊 View Reports" << endl;
    cout << "4. ❌ Exit" << endl;
    cout << string(60, '=') << endl;
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "            👤 ADMIN PANEL" << endl;
    cout << string(50, '=') << endl;
    cout << "1. 🏠 Room Management" << endl;
    cout << "2. 📊 Generate Reports" << endl;
    cout << "3. 👥 Customer Management" << endl;
    cout << "4. 🔓 Logout" << endl;
    cout << "5. ⬅️  Back to Main Menu" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

void displayRoomManagementMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "          🏠 ROOM MANAGEMENT" << endl;
    cout << string(50, '=') << endl;
    cout << "1. ➕ Add New Room" << endl;
    cout << "2. ❌ Remove Room" << endl;
    cout << "3. 💰 Modify Room Price" << endl;
    cout << "4. 📋 List All Rooms" << endl;
    cout << "5. 🔍 Filter Rooms by Price" << endl;
    cout << "6. ⬅️  Back to Admin Panel" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

void displayCustomerMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "          🛎️ CUSTOMER SERVICES" << endl;
    cout << string(50, '=') << endl;
    cout << "1. 🏨 Book a Room" << endl;
    cout << "2. 🛎️  Add Services" << endl;
    cout << "3. 🚪 Check Out" << endl;
    cout << "4. 📋 View Available Rooms" << endl;
    cout << "5. ⬅️  Back to Main Menu" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

void displayReportsMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "            📊 REPORTS" << endl;
    cout << string(50, '=') << endl;
    cout << "1. 👥 Customer Report" << endl;
    cout << "2. 📝 Booking Report" << endl;
    cout << "3. 🏠 Room Report" << endl;
    cout << "4. 📈 Occupancy Report" << endl;
    cout << "5. ⬅️  Back to Main Menu" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

void displayServiceMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "          🛎️ ADDITIONAL SERVICES" << endl;
    cout << string(50, '=') << endl;
    cout << "1. 🧺 Laundry Service" << endl;
    cout << "2. 🍽️  Meal Service" << endl;
    cout << "3. 🚗 Transport Service" << endl;
    cout << "4. ⬅️  Back to Customer Menu" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice: ";
}

// Room creation functions
Room* createStandardRoom() {
    cout << "\n--- Creating Standard Room ---\n";
    cout << "Enter room number: ";
    int roomNum = getValidInt();
    cout << "Enter price per day: $";
    double price = getValidDouble();
    cout << "Enter service fee: $";
    double serviceFee = getValidDouble();

    StandardRoom* room = new StandardRoom(roomNum, price, serviceFee);

    cout << "Add features? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string feature;
        cout << "Enter features (type 'done' to finish):\n";
        while (true) {
            cout << "Feature: ";
            getline(cin, feature);
            if (feature == "done") break;
            room->addFeature(feature);
        }
    }

    return room;
}

Room* createDeluxeRoom() {
    cout << "\n--- Creating Deluxe Room ---\n";
    cout << "Enter room number: ";
    int roomNum = getValidInt();
    cout << "Enter price per day: $";
    double price = getValidDouble();
    cout << "Enter service fee: $";
    double serviceFee = getValidDouble();
    cout << "Enter luxury tax: $";
    double tax = getValidDouble();

    DeluxeRoom* room = new DeluxeRoom(roomNum, price, serviceFee, tax);

    cout << "Add features? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string feature;
        cout << "Enter features (type 'done' to finish):\n";
        while (true) {
            cout << "Feature: ";
            getline(cin, feature);
            if (feature == "done") break;
            room->addFeature(feature);
        }
    }

    cout << "Add complimentary items? (y/n): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string item;
        cout << "Enter complimentary items (type 'done' to finish):\n";
        while (true) {
            cout << "Item: ";
            getline(cin, item);
            if (item == "done") break;
            room->addComplementaryItem(item);
        }
    }

    return room;
}

Room* createSuiteRoom() {
    cout << "\n--- Creating Suite Room ---\n";
    cout << "Enter room number: ";
    int roomNum = getValidInt();
    cout << "Enter price per day: $";
    double price = getValidDouble();
    cout << "Enter service fee: $";
    double serviceFee = getValidDouble();
    cout << "Enter luxury tax: $";
    double tax = getValidDouble();

    SuiteRoom* room = new SuiteRoom(roomNum, price, serviceFee, tax);

    cout << "Add features? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string feature;
        cout << "Enter features (type 'done' to finish):\n";
        while (true) {
            cout << "Feature: ";
            getline(cin, feature);
            if (feature == "done") break;
            room->addFeature(feature);
        }
    }

    cout << "Add complimentary items? (y/n): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string item;
        cout << "Enter complimentary items (type 'done' to finish):\n";
        while (true) {
            cout << "Item: ";
            getline(cin, item);
            if (item == "done") break;
            room->addComplementaryItem(item);
        }
    }

    return room;
}

// Service creation functions
Service* createLaundryService() {
    cout << "\n--- Laundry Service ---\n";
    cout << "1. Standard ($15/item)\n";
    cout << "2. Express ($25/item)\n";
    cout << "3. Dry Clean ($35/item)\n";
    cout << "Choose service type: ";
    int choice = getValidInt();

    string type;
    double price;
    switch (choice) {
        case 1: type = "Standard"; price = 15.0; break;
        case 2: type = "Express"; price = 25.0; break;
        case 3: type = "Dry Clean"; price = 35.0; break;
        default: type = "Standard"; price = 15.0; break;
    }

    cout << "Enter number of items: ";
    int items = getValidInt();

    return new LaundryService(type, price, items);
}

Service* createMealService() {
    cout << "\n--- Meal Service ---\n";
    cout << "1. Breakfast ($25/meal)\n";
    cout << "2. Lunch ($35/meal)\n";
    cout << "3. Dinner ($45/meal)\n";
    cout << "4. Room Service ($55/meal)\n";
    cout << "Choose meal type: ";
    int choice = getValidInt();

    string type;
    double price;
    switch (choice) {
        case 1: type = "Breakfast"; price = 25.0; break;
        case 2: type = "Lunch"; price = 35.0; break;
        case 3: type = "Dinner"; price = 45.0; break;
        case 4: type = "Room Service"; price = 55.0; break;
        default: type = "Breakfast"; price = 25.0; break;
    }

    cout << "Enter number of meals: ";
    int meals = getValidInt();

    return new MealService(type, price, meals);
}

Service* createTransportService() {
    cout << "\n--- Transport Service ---\n";
    cout << "1. Airport Pickup ($50 base)\n";
    cout << "2. City Tour ($80 base)\n";
    cout << "3. Taxi Service ($30 base)\n";
    cout << "Choose transport type: ";
    int choice = getValidInt();

    string type;
    double baseFare;
    switch (choice) {
        case 1: type = "Airport Pickup"; baseFare = 50.0; break;
        case 2: type = "City Tour"; baseFare = 80.0; break;
        case 3: type = "Taxi Service"; baseFare = 30.0; break;
        default: type = "Airport Pickup"; baseFare = 50.0; break;
    }

    cout << "Enter distance in km: ";
    double distance = getValidDouble();
    cout << "Enter rate per km ($): ";
    double rate = getValidDouble();

    return new TransportService(type, baseFare, distance, rate);
}

// Customer creation function
customer createCustomer() {
    cout << "\n--- Customer Information ---\n";
    string name, contact, id, checkIn, checkOut;
    int days;

    cin.ignore(); // Clear input buffer
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter contact number: ";
    getline(cin, contact);
    cout << "Enter ID number: ";
    getline(cin, id);
    cout << "Enter check-in date (YYYY-MM-DD): ";
    getline(cin, checkIn);
    cout << "Enter check-out date (YYYY-MM-DD): ";
    getline(cin, checkOut);
    cout << "Enter number of days: ";
    days = getValidInt();

    return customer(name, contact, id, 0, days, checkIn, checkOut);
}

// Menu handler functions
void handleRoomManagement(Admin& admin) {
    int choice;
    do {
        displayRoomManagementMenu();
        choice = getValidInt();

        switch (choice) {
            case 1: { // Add New Room
                cout << "\nSelect Room Type:\n";
                cout << "1. Standard Room\n";
                cout << "2. Deluxe Room\n";
                cout << "3. Suite Room\n";
                cout << "Enter choice: ";
                int roomType = getValidInt();

                Room* newRoom = nullptr;
                switch (roomType) {
                    case 1: newRoom = createStandardRoom(); break;
                    case 2: newRoom = createDeluxeRoom(); break;
                    case 3: newRoom = createSuiteRoom(); break;
                    default: cout << "Invalid choice!\n"; continue;
                }

                if (newRoom) {
                    admin.addNewRoom(newRoom);
                }
                pauseScreen();
                break;
            }
            case 2: { // Remove Room
                cout << "Enter room number to remove: ";
                int roomNum = getValidInt();
                admin.removeRoom(roomNum);
                pauseScreen();
                break;
            }
            case 3: { // Modify Price
                cout << "Enter room number: ";
                int roomNum = getValidInt();
                cout << "Enter new price: $";
                double newPrice = getValidDouble();
                admin.modifyRoomPrice(roomNum, newPrice);
                pauseScreen();
                break;
            }
            case 4: // List Rooms
                admin.listAvailableRooms();
                pauseScreen();
                break;
            case 5: { // Filter by Price
                cout << "Enter minimum price: $";
                double min = getValidDouble();
                cout << "Enter maximum price: $";
                double max = getValidDouble();
                admin.filterRoomsByPrice(min, max);
                pauseScreen();
                break;
            }
            case 6: // Back
                return;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
        }
    } while (choice != 6);
}

void handleCustomerServices(Hotel& hotel) {
    int choice;
    do {
        displayCustomerMenu();
        choice = getValidInt();

        switch (choice) {
            case 1: { // Book Room
                if (!hotel.hasRooms()) {
                    cout << "No rooms available. Please contact admin to add rooms.\n";
                    pauseScreen();
                    break;
                }

                customer newCustomer = createCustomer();

                cout << "\nSelect Room Type:\n";
                cout << "1. Standard\n";
                cout << "2. Deluxe\n";
                cout << "3. Suite\n";
                cout << "Enter choice: ";
                int roomTypeChoice = getValidInt();

                string roomType;
                switch (roomTypeChoice) {
                    case 1: roomType = "Standard"; break;
                    case 2: roomType = "Deluxe"; break;
                    case 3: roomType = "Suite"; break;
                    default: roomType = "Standard"; break;
                }

                hotel.bookRoom(newCustomer, roomType);
                pauseScreen();
                break;
            }
            case 2: { // Add Services
                cout << "Enter customer name: ";
                string customerName;
                cin.ignore();
                getline(cin, customerName);

                displayServiceMenu();
                int serviceChoice = getValidInt();

                Service* service = nullptr;
                switch (serviceChoice) {
                    case 1: service = createLaundryService(); break;
                    case 2: service = createMealService(); break;
                    case 3: service = createTransportService(); break;
                    case 4: return;
                    default: cout << "Invalid choice!\n"; continue;
                }

                if (service) {
                    hotel.addServiceToCustomer(customerName, service);
                }
                pauseScreen();
                break;
            }
            case 3: { // Check Out
                cout << "Enter customer name for checkout: ";
                string customerName;
                cin.ignore();
                getline(cin, customerName);
                hotel.checkOutCustomer(customerName);
                pauseScreen();
                break;
            }
            case 4: // View Available Rooms
                hotel.listAvailableRooms();
                pauseScreen();
                break;
            case 5: // Back
                return;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
        }
    } while (choice != 5);
}

void handleReports(Admin& admin) {
    int choice;
    do {
        displayReportsMenu();
        choice = getValidInt();

        switch (choice) {
            case 1: // Customer Report
                admin.generateReport("customers");
                pauseScreen();
                break;
            case 2: // Booking Report
                admin.generateReport("bookings");
                pauseScreen();
                break;
            case 3: // Room Report
                admin.generateReport("rooms");
                pauseScreen();
                break;
            case 4: // Occupancy Report
                admin.generateOccupancyReport();
                pauseScreen();
                break;
            case 5: // Back
                return;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
        }
    } while (choice != 5);
}

void handleAdminPanel(Admin& admin, Hotel& hotel) {
    if (!admin.isAuthenticated()) {
        if (!admin.login()) {
            return;
        }
    }

    int choice;
    do {
        displayAdminMenu();
        choice = getValidInt();

        switch (choice) {
            case 1: // Room Management
                handleRoomManagement(admin);
                break;
            case 2: // Generate Reports
                handleReports(admin);
                break;
            case 3: { // Customer Management
                cout << "\nCustomer Management Features:\n";
                cout << "1. View All Customers\n";
                cout << "2. View All Bookings\n";
                cout << "Enter choice: ";
                int custChoice = getValidInt();

                if (custChoice == 1) {
                    admin.generateReport("customers");
                } else if (custChoice == 2) {
                    admin.generateReport("bookings");
                }
                pauseScreen();
                break;
            }
            case 4: // Logout
                admin.logout();
                return;
            case 5: // Back
                return;
            default:
                cout << "Invalid choice!\n";
                pauseScreen();
        }
    } while (choice != 5);
}

int main() {
    Hotel myHotel;
    Admin admin("admin1", 1, &myHotel);

    cout << "🏨 Welcome to Hotel Management System! 🏨\n";
    cout << "Please set up your system first by adding rooms through Admin Panel.\n";
    pauseScreen();

    int mainChoice;
    do {
        clearScreen();
        displayMainMenu();
        mainChoice = getValidInt();

        switch (mainChoice) {
            case 1: // Admin Panel
                handleAdminPanel(admin, myHotel);
                break;
            case 2: // Customer Services
                handleCustomerServices(myHotel);
                break;
            case 3: // View Reports
                if (!admin.isAuthenticated()) {
                    cout << "Admin authentication required for reports.\n";
                    pauseScreen();
                } else {
                    handleReports(admin);
                }
                break;
            case 4: // Exit
                cout << "\n🙏 Thank you for using Hotel Management System!\n";
                cout << "Goodbye! 👋\n";
                break;
            default:
                cout << "❌ Invalid choice! Please try again.\n";
                pauseScreen();
        }
    } while (mainChoice != 4);

    return 0;
}
