#include <stdio.h> 
 #define MAX_FRAMES 3 
  
 int main() 
 { 
     int page_faults = 0, num_frames = 0; 
     int reference_string[] = {4, 1, 2, 4, 3, 2, 1, 5}; 
     int frames[MAX_FRAMES]; 
     int i, j, k; 
  
     // Initialize frames array to -1 (empty frame) 
     for (i = 0; i < MAX_FRAMES; i++) { 
         frames[i] = -1; 
     } 
  
     // Traverse the reference string 
     for (i = 0; i < 8; i++) { 
         int page = reference_string[i]; 
         int page_found = 0; 
  
         // Check if page is already in memory 
         for (j = 0; j < num_frames; j++) { 
             if (frames[j] == page) { 
                 page_found = 1; 
                 break; 
             } 
         } 
  
         // If page is not in memory, replace the oldest page 
         if (!page_found) { 
             frames[num_frames] = page; 
             num_frames++; 
  
             // If all frames are filled, replace the oldest page 
             if (num_frames > MAX_FRAMES) { 
                 page_faults++; 
                 num_frames = MAX_FRAMES; 
                 for (j = 0; j < MAX_FRAMES - 1; j++) { 
                     frames[j] = frames[j+1]; 
                 } 
                 frames[MAX_FRAMES-1] = page; 
             } 
             else { 
                 page_faults++; 
             } 
         } 
  
         // Print the current state of the memory 
         printf("%d -> ", page); 
         for (k = 0; k < num_frames; k++) { 
             printf("%d ", frames[k]); 
         } 
         printf("\n"); 
     } 
  
     printf("Number of page faults: %d\n", page_faults); 
  
     return 0; 
 }
