
# Parameters explanation:

- random_seed - a flag that represents whether the seed should be randomly piked 
- seed - specifies the seed should be used in case when "random_seed" is set to false
- filename - how the final image file should be named 
- width - width of the image in pixels
- height - height of the image in pixels
- num - number of centers of explosion 
- variety - basically, how "colorful" your image will be
- r - the array of length 2, where the first element represents the minimum red value for a pixel, and second value represents the maximum value  
- g - the array of length 2, where the first element represents the minimum green value for a pixel, and second value represents the maximum value
- b - the array of length 2, where the first element represents the minimum blue value for a pixel, and second value represents the maximum value
- random_center_xy - a flag that represents whether the position of the center of explosion is picked randomly
- center_x - the x position of center pixel if "random_center_xy" is set to false
- center_y - the y position of center pixel if "random_center_xy" is set to false
- random_center_col - a flag that represents whether the color of the center of explosion is picked randomly
- center_r - the red value of center pixel if "random_center_col" is set to false 
- center_g - the green value of center pixel if "random_center_col" is set to false
- center_b - the blue value of center pixel if "random_center_col" is set to false
- disruption - the probability of a pixel been "disrupted" (set to a random color regardless of the colors of neighbors)
- r_increase_probability - independent probability of red value to increase when propagating to the next pixel  
- g_increase_probability - independent probability of green value to increase when propagating to the next pixel
- b_increase_probability - independent probability of blue value to increase when propagating to the next pixel
- r_decrease_probability - independent probability of red value to decrease when propagating to the next pixel
- g_decrease_probability - independent probability of green value to decrease when propagating to the next pixel
- b_decrease_probability - independent probability of blue value to decrease when propagating to the next pixel