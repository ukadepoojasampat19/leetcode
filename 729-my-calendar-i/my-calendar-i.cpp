class MyCalendar {
public:
    MyCalendar() {
        // Initialize the calendar (empty at the start)
    }

    bool book(int start, int end) {
        // Iterate through the existing bookings to check for any conflicts
        for (const auto& booking : bookings) {
            // Check if the new event overlaps with any existing event
            if (max(start, booking.first) < min(end, booking.second)) {
                return false;  // Overlap detected, can't book this event
            }
        }

        // If no overlap, add the new event to the list of bookings
        bookings.push_back({start, end});
        return true;  // Successfully booked
    }

private:
    // A vector of pairs to store the start and end times of the booked events
    vector<pair<int, int>> bookings;
};
