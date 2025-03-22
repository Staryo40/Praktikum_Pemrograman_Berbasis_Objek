#include <iostream>
#include "TicketManager.hpp"

using namespace std;

int main() {
    // Membuat sistem Ticket Manager untuk acara "Music Festival"
    TicketManager manager("Music Festival");

    // Menampilkan nama acara
    cout << "Event Name: " << manager.getEventName() << endl;

    // Membeli tiket VIP dan Regular
    manager.buyTicket("Alice", true);  // VIP Ticket (V1)
    manager.buyTicket("Bob", false);   // Regular Ticket (R1)

    // Mengecek tiket yang telah dibeli
    manager.checkTicket("V1"); // Harus valid
    manager.checkTicket("R1"); // Harus valid
    manager.checkTicket("V2"); // Tidak valid

    // Menampilkan daftar penonton
    manager.listAudience();

    // Menghitung total pendapatan
    cout << "Total Revenue: " << manager.calculateRevenue() << " USD" << endl;

    return 0;
}

/* Output:
Event Name: Music Festival
Success: Alice bought a VIP ticket! Ticket ID: V1
Success: Bob bought a Regular ticket! Ticket ID: R1
V1 | VIP | Alice | Standard Entry + Soundcheck Access
R1 | Regular | Bob | Standard Entry
Ticket ID is invalid!
1. V1 | VIP | Alice | Standard Entry + Soundcheck Access
2. R1 | Regular | Bob | Standard Entry
Total Revenue: 775 USD
*/