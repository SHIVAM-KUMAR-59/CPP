/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

#include<iostream>
using namespace std;

class Solution{

    // Define a struct `Data` to store information about each meeting
    struct Data{
        int start;     // Start time of the meeting
        int end;       // End time of the meeting
        int position;  // Position of the meeting in the original input
    };

    public:
    int maxMeetings(vector<int> start, vector<int> end) {
        int n = start.size();  // Get the number of meetings

        // Create an array of `Data` objects to store each meeting's details
        Data arr[n];
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].position = i + 1;  // Store the original position (1-based index)
        }

        // Sort meetings by their end times (ascending) to ensure maximum utilization of time
        sort(arr, arr + n, [](Data a, Data b){
            return a.end < b.end;
        });

        int count = 1;                  // Initialize count with 1 for the first selected meeting
        int freeTime = arr[0].end;      // Set free time to end of the first meeting
        vector<int> order;              // To store the order of selected meetings
        order.push_back(arr[0].position); // Add the first meeting's position

        // Loop through the sorted meetings, starting from the second one
        for(int i = 1; i < n; i++){
            // Check if the current meeting can be accommodated
            if(arr[i].start > freeTime){
                count++;                     // Increase the count of meetings
                freeTime = arr[i].end;       // Update free time to the end of the current meeting
                order.push_back(arr[i].position); // Record the current meeting's position
            }
        }
        
        // The total count of meetings that can be accommodated
        return count;
    }
};
