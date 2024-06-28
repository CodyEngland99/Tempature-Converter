#include <iostream>
#include <cctype>

double fahrenheitToKevConversion(double input);
double fahrenheitToCelsiusConversion(double input);
double celsiusToFahConversion(double input);
double celsiusToKevConversion(double input);
double kelvinToFahConversion(double input);
double kelvinToCelConversion(double input);
double conversionFilter(int userConversionType, double userTemperature, int userTemperatureType);
int main() {
  int userConversionType;
  int userTemperatureType;
  double userTemperature;
  int finished = 0;

  do {
    std::cout << "What is your current temperature unit? (0 - Kelvin / 1 - Celsius / 2 - Fahrenheit)" << std::endl;
    
    while(!(std::cin >> userTemperatureType)) {
      std::cin.clear();
      std::cin.ignore();

      std::cout << "Please enter a valid choice ( 0 - 2 )" << std::endl;
    }

    std::cout << "What are you wanting to convert to? (0 - Kelvin / 1 - Celsius / 2 - Fahrenheit)" << std::endl;
    
    while(!(std::cin >> userConversionType)) {
      std::cin.clear();
      std::cin.ignore();

      std::cout << "Please enter a valid choice ( 0 - 2 )" << std::endl;
    }

    std::cout << "Please enter the temperature value" << std::endl;

    while(!(std::cin >> userTemperature)){
      std::cin.clear();
      std::cin.ignore();

      std::cout << "Please enter a valid number" << std::endl;
    }

    std::cout << conversionFilter(userConversionType, userTemperature, userTemperatureType) << " degrees" << std::endl; 


    std::cout << "Would you like to convert another temperature? ( 0 - Yes / 1 - No )" << std::endl;
      while(!(std::cin >> finished)){
      std::cin.clear();
      std::cin.ignore();

      std::cout << "Please enter a valid number" << std::endl;
    }


  } while (finished == 0);

  std::cin.clear();
  std::cin.ignore();

  return 0;
}

double conversionFilter(int userConversionType, double userTemperature, int userTemperatureType) {
      switch (userTemperatureType) {
      case 0: {
        if (userConversionType == 1) {
          userTemperature =  kelvinToCelConversion(userTemperature);
          break;
        } else if (userConversionType == 2){
          userTemperature = kelvinToFahConversion(userTemperature);
          break;
        } else {
          std::cout << userTemperature << '\302' << '\260' << "K" << std::endl;
        }
        break;
      } 
      case 1: {
      if (userConversionType == 0) {
          userTemperature = celsiusToKevConversion(userTemperature);
          break;
        } else if (userConversionType == 2){
          userTemperature = celsiusToFahConversion(userTemperature);
          break;
        } else {
          std::cout << userTemperature << '\302' << '\260' << "C" << std::endl;
        }
        break;
      } 
      case 2: {
        if (userConversionType == 1) {
          userTemperature = fahrenheitToCelsiusConversion(userTemperature);
          break;
        } else if (userConversionType == 0){
          userTemperature = fahrenheitToKevConversion(userTemperature);
          break;
        } else {
          std::cout << userTemperature << '\302' << '\260'<< "F" << std::endl;
        }
        break;
      } 
      default : {
        std::cout << "There was a error please try again" << std::endl;
        break;
      }
    }

  return userTemperature;
}

double kelvinToCelConversion(double input) {
  return input - 273.15;
}

double kelvinToFahConversion(double input) {
  return (input - 273.15) * 1.8 + 32;
}

double celsiusToKevConversion(double input) {
  return input + 273.15;
}

double celsiusToFahConversion(double input) {
  return input * 1.8 + 32;
}

double fahrenheitToCelsiusConversion(double input) {
  return (input - 32) * 0.5556;
}

double fahrenheitToKevConversion(double input) {
  return (input - 32) * 0.5556 + 273.15;
}
