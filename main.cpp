#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
        cout << "Deluxe Room Number: " << getRoomNumber() << endl;
        cout << "Type: " << getRoomType() << endl;
        cout << "Price per Day: " << getPricePerDay() << endl;
        cout << "Service Fee: " << serviceFee << endl;
        cout << "Luxury Tax: " << luxuryTax << endl;
        cout << "Available: " << isRoomAvailable()  << endl;


    cout << "Features: ";
    for (const string& feature : getFeatures()) {
        cout << feature << ", ";
    }
    cout << endl;

    cout << "Complementary Items: ";
    for (const string& item: complementaryItems) {
        cout << item<< ", ";
    }
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
        cout << "Suite Room Number: " << getRoomNumber() << endl;
        cout << "Type: " << getRoomType() << endl;
        cout << "Price per Day: " << getPricePerDay() << endl;
        cout << "Service Fee: " << serviceFee << endl;
        cout << "Luxury Tax: " << luxuryTax << endl;
        cout << "Available: " << isRoomAvailable()  << endl;


    cout << "Features: ";
    for (const string & feature : getFeatures()) {
        cout << feature << ", ";
    }
    cout << endl;

    cout << "Complementary Items: ";
    for (const string& item : complementaryItems) {
        cout << item << ", ";
    }
    }

};
/**3. Customer
 Attributes: name, contact, idNumber, bookedRoomNumber, daysOfStay, checkInDate,
checkOutDate, loyaltyPoints
 Methods:
o assignRoom(Room* r, int days)
o displayCustomerDetails()
o generateInvoice()
o void updateLoyaltyPoints( */
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
        cout << "Customer Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "ID Number: " << idNumber << endl;
        cout << "Booked Room Number: " << bookedRoomNumber << endl;
        cout << "Days of Stay: " << daysOfStay << endl;
        cout << "Check-In Date: " << checkInDate << endl;
        cout << "Check-Out Date: " << checkOutDate << endl;
        cout << "Loyalty Points: " << loyaltyPoints << endl;
    }
    void generateInvoice(const Room & r) const {
        double totalBill = r.calculateBill(daysOfStay);
        cout << "Invoice for Customer: " << name << endl;
        cout << "Room Number: " << bookedRoomNumber << endl;
        cout << "Days of Stay: " << daysOfStay << endl;
        cout << "Total Bill: $" << totalBill << endl;
    }
    void updateLoyaltyPoints() {
        loyaltyPoints += daysOfStay * 10;

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



};

/**4. Booking
 Attributes: bookingID, Customer, Room, bookingDate, checkOutDate, totalBill,
status
 Methods:
o confirmBooking()
o cancelBooking()
o modifyBookingDetails()
o displayBookingDetails() */




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
            int days=cust.getDaysOfStay();
            totalBill = room->calculateBill(days);
            cout << "Booking details modified. New days of stay: " << days << ", Total Bill: $" << totalBill << endl;
            cout << "Booking confirmed for " << cust.getName()  << " in room " << room->getRoomNumber() << endl;

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

        totalBill = room->calculateBill(newDays);
        cout << "Booking details modified. New days of stay: " << newDays << ", Total Bill: $" << totalBill << endl;
    }

    void displayBookingDetails() const {
        cout << "Booking ID: " << bookingID << endl;
        cust.displayCustomerDetails();
        cout << "Room Number: " << room->getRoomNumber() << endl;
        cout << "Booking Date: " << bookingDate << endl;
        cout << "Check-Out Date: " << checkOutDate << endl;
        cout << "Total Bill: $" << totalBill << endl;
        cout << "Status: " << status << endl;
    }

string getCustomerName() const { return cust.getName(); }

     string getStatus(){
     return status;
     }

};
int Booking::nextBookingID = 1;




#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
        for (Room* room : list_of_rooms) {
            if (room->isRoomAvailable()) {
                if (filterByFeature.empty()) {
                    room->displayInfo();
                } else {
                    for (string feature : room->getFeatures()) {
                        if (feature == filterByFeature) {
                            room->displayInfo();
                            break;
                        }
                    }
                }
            }
        }
    }

    void bookRoom(customer cust, string roomType) {
        for (Room* room : list_of_rooms) {
            if (room->getRoomType() == roomType && room->isRoomAvailable()) {
                cust.assignRoom(*room, cust.getDaysOfStay());
                Booking booking(cust, room);
                booking.confirmBooking();
                list_of_customers.push_back(cust);
                list_of_bookings.push_back(booking);
                return;
            }
        }
        cout << "No available room found for type: " << roomType << endl;
    }

    void checkOutCustomer(string customerName) {
        for (Booking& booking : list_of_bookings) {
            if (booking.getCustomerName() == customerName && booking.getStatus() == "Confirmed") {
                booking.cancelBooking();  // Change to checkout logic if needed
                return;
            }
        }
        cout << "No active booking found for customer: " << customerName << endl;
    }

    void generateReport(string reportType) {
        if (reportType == "customers") {
            cout << "\nCustomer Report:\n";
            for (const customer& cust : list_of_customers) {
                cust.displayCustomerDetails();
            }
        } else if (reportType == "bookings") {
            cout << "\nBooking Report:\n";
            for (const Booking& b : list_of_bookings) {
                b.displayBookingDetails();
            }
        } else {
            cout << "Unknown report type: " << reportType << endl;
        }
    }

    void filterRoomsByPriceRange(double minPrice, double maxPrice) {
        cout << "\nRooms in Price Range [" << minPrice << ", " << maxPrice << "]:\n";
        for (Room* room : list_of_rooms) {
            double price = room->getPricePerDay();
            if (price >= minPrice && price <= maxPrice) {
                room->displayInfo();
            }
        }
    }
};

class Admin {
private:
    string username;
    string password;
    int adminLevel;

public:
    Admin(string user, string pass, int level)
        : username(user), password(pass), adminLevel(level) {}

    bool login() {
        string inputPass;
        int attempts = 3;

        while (attempts--) {
            cout << "Enter password for admin (" << username << "): ";
            cin >> inputPass;

            if (inputPass == password) {
                cout << "Login successful!\n";
                return true;
            } else {
                cout << "Incorrect password. ";
                if (attempts > 0)
                    cout << "Try again.\n";
            }
        }

        cout << "Access denied after multiple attempts.\n";
        return false;
    }

    void displayAdminDetails() const {
        cout << "Admin Username: " << username << endl;
        cout << "Admin Level: " << adminLevel << endl;
    }

    string getUsername() const {
        return username;
    }

    int getAdminLevel() const {
        return adminLevel;
    }

    void addNewRoom(Hotel& hotel) {
    int number;
    double price, serviceFee, tax;
    string type;

    cout << "Enter Room Number: ";
    cin >> number;
    cout << "Enter Room Type (Deluxe/Suite): ";
    cin >> type;
    cout << "Enter Price Per Day: ";
    cin >> price;
    cout << "Enter Service Fee: ";
    cin >> serviceFee;
    cout << "Enter Luxury Tax: ";
    cin >> tax;

    Room* newRoom = nullptr;
    if (type == "Deluxe") {
        newRoom = new DeluxeRoom(number, price, serviceFee, tax);
    } else if (type == "Suite") {
        newRoom = new SuiteRoom(number, price, serviceFee, tax);
    }

    if (newRoom) {
        hotel.addRoom(newRoom);  // ✅ Now valid
    } else {
        cout << "Invalid room type.\n";
    }
}




};


int main() {
    Hotel myHotel;

    // Create Deluxe Rooms (roomNumber, pricePerDay, serviceFee, luxuryTax)
    Room* room1 = new DeluxeRoom(101, 150.0, 20.0, 15.0);
    Room* room2 = new DeluxeRoom(102, 180.0, 25.0, 18.0);

    // Add some features and complementary items for demonstration
    room1->addFeature("WiFi");
    room1->addFeature("Air Conditioning");
    dynamic_cast<DeluxeRoom*>(room1)->addComplementaryItem("Free Breakfast");

    room2->addFeature("Sea View");
    room2->addFeature("Mini Bar");
    dynamic_cast<DeluxeRoom*>(room2)->addComplementaryItem("Spa Access");

    // Add rooms to hotel
    myHotel.addRoom(room1);
    myHotel.addRoom(room2);

    // Create a customer (name, contact, id, bookedRoom(0 for now), daysOfStay, checkInDate, checkOutDate)
    customer cust1("Alice", "555-1234", "ID001", 0, 3, "2025-06-10", "2025-06-13");

    // Book a Deluxe room for customer Alice
    myHotel.bookRoom(cust1, "Deluxe");

    // List available rooms after booking
    myHotel.listAvailableRooms();

    // Generate customer report
    myHotel.generateReport("customers");

    // Generate booking report
    myHotel.generateReport("bookings");

    // Filter rooms by price range
    myHotel.filterRoomsByPriceRange(100.0, 160.0);

    // Check out customer Alice
    myHotel.checkOutCustomer("Alice");

    // List available rooms again after checkout
    myHotel.listAvailableRooms();

    // Clean up dynamically allocated memory
    delete room1;
    delete room2;


    // Create an admin object
    Admin admin1("admin", "1234", 2);

    // Login prompt
    if (admin1.login()) {
        // Show details if login successful
        admin1.displayAdminDetails();
        cout << "✅ You can now access admin features here...\n";
    } else {
        cout << "🚫 Exiting system due to failed login.\n";
    }


    return 0;
}
