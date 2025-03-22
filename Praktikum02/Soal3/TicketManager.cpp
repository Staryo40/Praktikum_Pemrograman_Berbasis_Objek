#include <iostream>
#include <string>
#include "TicketManager.hpp"
using namespace std;

TicketManager::TicketManager(string eventName)
/* Constructor default:
    * - Membuat event dengan nama yang diberikan.
    * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
    * - Tidak ada tiket yang terjual pada awalnya.
    */
{
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
    for (int i = 0; i < VENUE_CAPACITY; i++) {
        this->tickets[i] = nullptr;
    }
}


TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity)
/* Constructor dengan kapasitas yang ditentukan:
    * - Membuat event dengan kapasitas khusus untuk VIP dan Regular.
    * - Jika total kapasitas melebihi VENUE_CAPACITY, cetak:
    *   "The total capacity you construct is <total>, meanwhile the venue capacity is 15"
    */
{   
    int totalCapacity = vipCapacity + regularCapacity;
    if (totalCapacity > VENUE_CAPACITY){
        cout << "The total capacity you construct is " << totalCapacity << ", meanwhile the venue capacity is 15" << endl;
    } 
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
    for (int i = 0; i < VENUE_CAPACITY; i++) {
        this->tickets[i] = nullptr;
    }
}

TicketManager::~TicketManager()
/* Destructor:
    * - Membersihkan semua tiket yang telah dialokasikan secara dinamis.
    * - Menetapkan pointer tiket menjadi nullptr setelah dihapus.
    */
{
    for (int i = 0; i < VENUE_CAPACITY; i++){
        delete this->tickets[i];
        this->tickets[i] = nullptr;
    }
}

string TicketManager::getEventName() const
/* Mengembalikan nama acara yang dikelola oleh TicketManager.
    * Output: Nama acara dalam bentuk string.
    */
{
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP)
/* Membeli tiket untuk pengguna.
* Input:
* - ownerName: Nama pemilik tiket.
* - isVIP: Jika true, membeli tiket VIP; jika false, membeli tiket Regular.
*
* Proses:
* - Jika venue penuh, cetak "Error: All tickets are sold out!".
* - Jika kapasitas VIP penuh, cetak "Error: No VIP tickets left!".
* - Jika kapasitas Regular penuh, cetak "Error: No Regular tickets left!".
*
* - Jika pembelian berhasil, sistem akan membuat **ID tiket unik** berdasarkan jenis tiket:
*   - Jika tiket VIP, ID akan berupa "V" diikuti nomor urut tiket VIP.
*   - Jika tiket Regular, ID akan berupa "R" diikuti nomor urut tiket Regular.
*
* - Contoh penggunaan `to_string()` dalam pembuatan ID:
*   int angka = 5;
*   string hasil = "V" + to_string(angka); // hasil: "V5"
*
* - Jika pembelian berhasil, cetak:
*   "Success: <ownerName> bought a <VIP/Regular> ticket! Ticket ID: <ticketID>"
*/
{
    if (this->ticketCount == VENUE_CAPACITY)
    {
        cout << "Error: All tickets are sold out!" << endl;
    } else {
        if (isVIP){
            if (this->vipCapacity == this->currentVIPTickets){
                cout << "Error: No VIP tickets left!" << endl;
            } else {
                int newID = this->currentVIPTickets + 1;
                string id = "V" + to_string(newID);
                cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << id << endl;
                
                this->tickets[ticketCount] = new VIPTicket(id, ownerName);
                this->currentVIPTickets++;
                this->ticketCount++;
            }
        } else {
            if (this->regularCapacity == this->currentRegularTickets){
                cout << "Error: No Regular tickets left!" << endl;
            } else {
                int newID = this->currentRegularTickets + 1;
                string id = "R" + to_string(newID);
                cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << id << endl;

                this->tickets[ticketCount] = new RegularTicket(id, ownerName);
                this->currentRegularTickets++;
                this->ticketCount++;
            }
        }
    }
    
    
}

void TicketManager::checkTicket(const string &ticketID) const
/* Mengecek apakah tiket dengan ID tertentu valid.
    * Input:
    * - ticketID: ID tiket yang ingin diperiksa.
    *
    * Output:
    * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
    * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
    */
{
    bool found = false;
    for (int i = 0; i < ticketCount; i++){
        if (ticketID == this->tickets[i]->getTicketID()){
            this->tickets[i]->printTicket();
            found = true;
            break;
        }
    }
    if (!found){
         cout << "Ticket ID is invalid!" << endl;
    }
}
void TicketManager::listAudience() const
/* Menampilkan daftar semua pemegang tiket.
    * Output:
    * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
    * - Jika ada, cetak dalam format:
    *   "<nomor>. <printTicket()>"
    *
    * - Nomor urut dalam output harus dimulai dari 1.
    */
{
    if (ticketCount == 0){
        cout << "No audience yet!" << endl;
    } else {
        for (int i = 0; i < ticketCount; i++){
            cout << i+1 << ". ";
            this->tickets[i]->printTicket();
        }
    }
}

int TicketManager::calculateRevenue() const
/* Menghitung total pendapatan dari tiket yang terjual.
    * - Tiket VIP seharga 500.
    * - Tiket Regular seharga 275.
    * 
    * Output: Total pendapatan dalam bentuk integer.
    */
{
    int res = this->currentRegularTickets * 275 + this->currentVIPTickets * 500;
    return res;
}