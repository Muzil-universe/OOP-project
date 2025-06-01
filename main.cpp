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

};
int Booking::nextBookingID = 1;
int main() {
    // Create a Deluxe Room
    DeluxeRoom d1(101, 250.0, 40.0, 30.0);
    d1.addFeature("Sea View");
    d1.addFeature("Flat TV");
    d1.addComplementaryItem("Breakfast");

    // Create a Customer
    customer c1("Alice", "03001234567", "CNIC001", 0, 3, "2025-06-02", "2025-06-05");

    // Assign room to customer (this also sets room as booked)
    c1.assignRoom(d1, 3);

    // Create a Booking for this customer and room
    Booking b1(c1, &d1);
    b1.confirmBooking();           // Confirm booking
    b1.displayBookingDetails();    // Show details

    cout << "\n--- Modifying booking to 5 days ---\n";
    b1.modifyBookingDetails(5);    // Update stay duration
    b1.displayBookingDetails();    // Show updated details

    cout << "\n--- Cancelling booking ---\n";
    b1.cancelBooking();            // Cancel it
    b1.displayBookingDetails();    // Show final state

    return 0;
}


  

