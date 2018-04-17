#include "../TEST SUITE/TestSuite.h"
#include "../TEST CASES/TestCases.h"
#include "../TEST SUITE/TestExamples.h"



// Define to use specific tests
#define SAMPLES_TESTS					0
#define D2XX_TESTS						1
#define MPSSE_I2C_TESTS					1
#define MPSSE_I2C_EEPROM24LC024H_TESTS	0 // enable only if you have I2C EEPROM 24LC024H
#define MPSSE_SPI_TESTS					1
#define MPSSE_SPI_EEPROM93LC56B_TESTS	0 // enable only if you have SPI EEPROM 93LC56B
#define LOOPBACK_TESTS					0



// Update to customize the file name of the log file
std::string TEST_CONFIG_LOG_FILE_NAME = "TestSuite_FT4232.log";

// Update to stop loop after some test failed
bool TEST_CONFIG_STOPWHENFAIL = false;

// Update to continuously run the test
bool TEST_CONFIG_STRESSTEST = false;

// Update to set default loopback size
int TEST_CONFIG_TEST_DEFAULT_LOOPBACK_SIZE = 4096;


// Updated using argument passed to the program
std::string TEST_CONFIG_DEVICE_NAME = "";
std::string TEST_CONFIG_DEVICE_NAME_2 = "";
bool TEST_CONFIG_TERMINATE_ALL_TESTS = false;

bool DeviceNameIsSet() {
	return (TEST_CONFIG_DEVICE_NAME != "");
}

bool DeviceNameCompare(const char* pcDeviceName) {
	std::string szDeviceName = pcDeviceName;
	std::transform(szDeviceName.begin(), szDeviceName.end(), szDeviceName.begin(), ::tolower);
	return (TEST_CONFIG_DEVICE_NAME == szDeviceName);
}

void DeviceNameNotFoundAbort() {
	TEST_CONFIG_TERMINATE_ALL_TESTS = true;
}

bool DeviceNameIsSetEx() {
	return (TEST_CONFIG_DEVICE_NAME != "" && TEST_CONFIG_DEVICE_NAME_2 != "");
}

bool DeviceNameCompareEx(const char* pcDeviceName) {
	std::string szDeviceName = pcDeviceName;
	std::transform(szDeviceName.begin(), szDeviceName.end(), szDeviceName.begin(), ::tolower);
	return (TEST_CONFIG_DEVICE_NAME == szDeviceName || TEST_CONFIG_DEVICE_NAME_2 == szDeviceName);
}


// Update to include all the test cases
std::vector<TEST_CASE> TEST_CONFIG_TEST_CASES =
{
#if SAMPLES_TESTS
	{ ExampleTest1, "ExampleTest1" },
	{ ExampleTest2, "ExampleTest2" },
	{ ExampleTest3, "ExampleTest3" },
#endif //SAMPLES_TESTS

	// -------------------------------------------------------------
	// Add test cases below ...
	// -------------------------------------------------------------

#if D2XX_TESTS
	{ FT4232_D2XX_Info,							"FT4232_D2XX_Info"				},
	{ FT4232_D2XX_Enumerate,					"FT4232_D2XX_Enumerate"			},
	{ FT4232_D2XX_Open,							"FT4232_D2XX_Open"				},
	{ FT4232_D2XX_ResetPort,					"FT4232_D2XX_ResetPort"			},
	{ FT4232_D2XX_CyclePort,					"FT4232_D2XX_CyclePort"			},
	{ FT4232_D2XX_ResetDevice,					"FT4232_D2XX_ResetDevice"		},
	{ FT4232_D2XX_SetSync245,					"FT4232_D2XX_SetSync245"		},
	{ FT4232_D2XX_UnsetSync245,					"FT4232_D2XX_UnsetSync245"		},
	//{ FT4232_D2XX_UART,						"FT4232_D2XX_UART"				},
	//{ FT4232_D2XX_SPIUnmanaged,				"FT4232_D2XX_SPIUnmanaged"		},
#endif // D2XX_TESTS

#if MPSSE_I2C_TESTS
	{ FT4232_MPSSE_I2C_Enumerate,				"FT4232_MPSSE_I2C_Enumerate"			},
	{ FT4232_MPSSE_I2C_Open,					"FT4232_MPSSE_I2C_Open"					},
	{ FT4232_MPSSE_I2C_Configure,				"FT4232_MPSSE_I2C_Configure"			},
#if MPSSE_I2C_EEPROM24LC024H_TESTS
	{ FT4232_MPSSE_I2C_IO_EEPROM24LC024H,		"FT4232_MPSSE_I2C_IO_EEPROM24LC024H"	},
#endif // MPSSE_I2C_EEPROM24LC024H_TESTS
	{ FT4232_MPSSE_I2C_GPIO,					"FT4232_MPSSE_I2C_GPIO"					},
#endif // MPSSE_I2C_TESTS

#if MPSSE_SPI_TESTS
	{ FT4232_MPSSE_SPI_Enumerate,				"FT4232_MPSSE_SPI_Enumerate"			},
	{ FT4232_MPSSE_SPI_Open,					"FT4232_MPSSE_SPI_Open"					},
	{ FT4232_MPSSE_SPI_Configure,				"FT4232_MPSSE_SPI_Configure"			},
#if MPSSE_SPI_EEPROM93LC56B_TESTS
	{ FT4232_MPSSE_SPI_IO_EEPROM93LC56B,		"FT4232_MPSSE_SPI_IO_EEPROM93LC56B"		},
#endif // MPSSE_SPI_EEPROM93LC56B_TESTS
	{ FT4232_MPSSE_SPI_GPIO,					"FT4232_MPSSE_SPI_GPIO"					},
#endif // MPSSE_SPI_TESTS

#if LOOPBACK_TESTS
	{ FT4232_LOOPBACK_2Threads2Devices,			"FT4232_LOOPBACK_2Threads2Devices"		},
#endif // LOOPBACK_TESTS

	// -------------------------------------------------------------
	// Add test cases above ...
	// -------------------------------------------------------------

	{ NULL, "" }, // Do not modify. Last test case should be NULL.
};

std::vector<TEST_CASE> TEST_CONFIG_TEST_CASES_2 =
{
	{ FT4232_LOOPBACK_2Threads2Devices,			"FT4232_LOOPBACK_2Threads2Devices"		},
	{ NULL, "" }, // Do not modify. Last test case should be NULL.
};

std::vector<TEST_CASE> TEST_CONFIG_TEST_CASES_3 =
{
	{ NULL, "" }, // Do not modify. Last test case should be NULL.
};

std::vector<TEST_CASE> TEST_CONFIG_TEST_CASES_4 =
{
	{ FT4232_D2XX_JTAG_TISN74BCT8244A,			"FT4232_D2XX_JTAG_TISN74BCT8244A"		},
	{ FT4232_MPSSE_JTAG_TISN74BCT8244A,			"FT4232_MPSSE_JTAG_TISN74BCT8244A"		},
	{ FT4232_MPSSE_JTAG_TISN74BCT8244A_2,		"FT4232_MPSSE_JTAG_TISN74BCT8244A_2"	},

	{ NULL, "" }, // Do not modify. Last test case should be NULL.
};

std::vector<TEST_CASE> TEST_CONFIG_TEST_CASES_5 =
{
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_Enumerate,"FT4232_MPSSE_SPIFlash_W25Q128JV_Enumerate" },
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_Open,		"FT4232_MPSSE_SPIFlash_W25Q128JV_Open"		},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_ReadIDs,	"FT4232_MPSSE_SPIFlash_W25Q128JV_ReadIDs"	},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_Power,	"FT4232_MPSSE_SPIFlash_W25Q128JV_Power"		},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_Suspend,	"FT4232_MPSSE_SPIFlash_W25Q128JV_Suspend"	},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_BasicIO,	"FT4232_MPSSE_SPIFlash_W25Q128JV_BasicIO"	},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_SimpleIO,	"FT4232_MPSSE_SPIFlash_W25Q128JV_SimpleIO"	},
	{ FT4232_MPSSE_SPIFlash_W25Q128JV_Erase,	"FT4232_MPSSE_SPIFlash_W25Q128JV_Erase"		},

	{ NULL, "" }, // Do not modify. Last test case should be NULL.
};
