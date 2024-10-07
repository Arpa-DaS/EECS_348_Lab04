#include <stdio.h>

// Function prototypes  functions that will be used later in the program.
float celsius_to_fahrenheit(float celsius);// Converts Celsius to Fahrenheit
float fahrenheit_to_celsius(float fahrenheit);// Converts Fahrenheit to Celsius
float celsius_to_kelvin(float celsius);// Converts Celsius to Kelvin
float kelvin_to_celsius(float kelvin);// Converts Kelvin to Celsius
float fahrenheit_to_kelvin(float fahrenheit);// Converts Fahrenheit to Kelvin
float kelvin_to_fahrenheit(float kelvin);// Converts Kelvin to Fahrenheit
void categorize_temperature(float celsius);// Categorizes temperature into weather types
void print_weather_advisory(const char* category);// Provides a weather advisory based on category

// Main function it starts executing
int main() {
    float temperature, converted_temperature;// used to store the input and the converted temperature
    int input_scale, target_scale;// Store the temperature scale options chosen by the user

//getting the temperature from the user
    printf("Enter the temperature: ");
    if (scanf("%f", &temperature) != 1) { //checking if its a valid number
        printf("Invalid input. Please enter a valid number.\n");
        return 1; //the program will exit if the input is invalid
    }

    // asking user for Celcius, Fahrenheit,Kelvin
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid choice for scale.\n"); //if its not a valid choice its going to exit the program in next line and return this message
        return 1;
    }

    // asking what to convert to
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid choice for conversion.\n");
        return 1;
    }

    // making sure that they dont convert to the same scale
    if (input_scale == target_scale) {
        printf("Input scale and target scale cannot be the same.\n");
        return 1;
    }

    // doing the conversions based on what the user choose
    switch (input_scale) {
        case 1: // input was Celcius
            if (target_scale == 2) { //converting to Fahrenheit
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("Converted temperature: %.2f°F\n", converted_temperature);
            } else if (target_scale == 3) { //Converting to Kelvin
                converted_temperature = celsius_to_kelvin(temperature);
                printf("Converted temperature: %.2fK\n", converted_temperature);
            }
            break;
        case 2: // input was Fahrenheit
            if (target_scale == 1) { //to Celsius
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("Converted temperature: %.2f°C\n", converted_temperature);
            } else if (target_scale == 3) {//to Kelvin
                converted_temperature = fahrenheit_to_kelvin(temperature);
                printf("Converted temperature: %.2fK\n", converted_temperature);
            }
            break;
        case 3: // input was Kelvin
            if (temperature < 0) { //making it so that Kelvin can't be negative 
                printf("Invalid temperature: Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1) { //converting to celsius
                converted_temperature = kelvin_to_celsius(temperature);
                printf("Converted temperature: %.2f°C\n", converted_temperature);
            } else if (target_scale == 2) { //converting to fahrenheit
                converted_temperature = kelvin_to_fahrenheit(temperature);
                printf("Converted temperature: %.2f°F\n", converted_temperature);
            }
            break;
    }

    // the temperatures are now going to be categorized to give a weather advisory it will al be categorized in Celsius
    if (target_scale == 1) { //if the converted scale is in Celsius then it will be categorize it
        categorize_temperature(converted_temperature);
    } else if (input_scale == 1) {//if the input scale is Celsius categorize it
        categorize_temperature(temperature);
    } else if (input_scale == 2) {// if the input is Fahrenheit, convert to Celsius for categorization
        categorize_temperature(fahrenheit_to_celsius(temperature));
    } else if (input_scale == 3) {// if the input is in kelvin, convert it to celcius for categorization
        categorize_temperature(kelvin_to_celsius(temperature));
    }

    return 0;
}

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32; //converting celsius to fahrenheit
}

float fahrenheit_to_celsius(float fahrenheit) { //converting fhrenheit to celsius
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) { //converting celsius to kelvin
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) { //kel to cel
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) { //fahren to kel
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) { //kel to fah
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorize and provide weather advisory based on Celsius temperature
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        print_weather_advisory("Freezing");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        print_weather_advisory("Cold");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        print_weather_advisory("Comfortable");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        print_weather_advisory("Hot");
    } else if (celsius >= 35) {
        printf("Temperature category: Extreme Heat\n");
        print_weather_advisory("Extreme Heat");
    }
}

// Prints the weather advisory
void print_weather_advisory(const char* category) {
    if (category == "Freezing") {
        printf("Weather advisory: Stay indoors you could turn into an icicle, it's freezing!\n");
    } else if (category == "Cold") {
        printf("Weather advisory: Wear a jacket, it's cold.\n");
    } else if (category == "Comfortable") {
        printf("Weather advisory: It's your lucky day its comfortable!\n");
    } else if (category == "Hot") {
        printf("Weather advisory: Make sure to drink water. It's hot.\n");
    } else if (category == "Extreme Heat") {
        printf("Weather advisory: Maybe stay in? It's extremely hot!\n");
    }
}
