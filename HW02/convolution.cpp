#include "convolution.h"

void convolution(const float *image, float *output, std::size_t n, const float *mask, std::size_t m){
    using std::size_t;
    const size_t mask_shift = m / 2;    //Since the shift will need to be computed every inner loop do it once here instead

    for (size_t x=0; x<n; x++){         //Loops through the rows in image 
        for (size_t y=0; y<n; y++){     //Loops through the pixels in the image
            float sum = 0.0f;           //Intialize the sum to be calculated to 0 so it doesn't carry over between pixels
            for (size_t i=0; i<m; i++){     //Loop through the rows in the mask
                for (size_t j=0; j<m; j++){     //Loop through the columns in the mask
                    int image_x = static_cast<int>(x) + static_cast<int>(i) - static_cast<int>(mask_shift); //Compute the shift of x on the image
                    int image_y = static_cast<int>(y) + static_cast<int>(j) - static_cast<int>(mask_shift); //Compute the shift of y on the image

                    float image_value;  //Variable to save the value of f/the image

                    //If the shifted image value is in the original image use it
                    if (image_x >= 0 && image_x < static_cast<int>(n) && image_y >= 0 && image_y < static_cast<int>(n)){    
                        image_value = image[image_x * n + image_y];
                    }
                    //If only one of the images shifted coordinates is in the orginal image use a value of 1
                    else if ((image_x >= 0 && image_x < static_cast<int>(n)) || (image_y >= 0 && image_y < static_cast<int>(n))){   
                        image_value = 1.0f;
                    }
                    //If neither shifted coordinate is in the original image set the value to 0
                    else {
                        image_value = 0.0f;
                    }
                    sum += mask[i*m*j] * image_value;   //Add to the sum for this pixel in the output
                }
            }
            output[x * n + y] = sum;    //Save the value of the sum into the output pixel
        }
    }
}