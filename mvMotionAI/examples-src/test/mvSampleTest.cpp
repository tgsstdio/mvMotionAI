/**
 * Simple CPPUnit Console Test Result Outputter
 * Expanded Money Test Suite example from CPPUnit Cookbook
 *
 * HOW TO USE: compile any derived CPPUnit test suite then auto register
 * by using helper macros. After that link the test suite object file with
 * this file's object (along with CPPUni's library modules), to get an
 * executable.
 *
 * Commad line arguments and optional code output by
 * David Young, 2007
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#define PROGRAM_NAME_INDEX 0
#define OUTPUTTER_TYPE_INDEX 1
#define OUTPUTTER_STREAM_INDEX 2
#define OUTPUTTER_FILENAME_INDEX 3
// TODO : allowing file arguments such as append
#define OUTPUTTER_FILE_MODES_INDEX 4

#define MAX_NO_OF_OUTPUTTER_ARGS 4

enum outputterTypeEnums
{
OUTPUTTER_COMPILER_GCC_OUTPUT = 0,
OUTPUTTER_XML_OUTPUT,
OUTPUTTER_TEXT_OUTPUT,
OUTPUTTER_COMPILER_VCPLUSPLUS_OUTPUT,
NO_OF_OUTPUTTER_TYPES
};

const char* outputterTypeStrings[] =
{
"COMPILER : GCC",
"XML",
"PLAIN TEXT",
"COMPILER : VC++",
};

enum outputterStreamEnums
{
OUTPUTTER_STREAM_STDOUT = 0,
OUTPUTTER_STREAM_STDERR,
OUTPUTTER_STREAM_FILE_REDIRECT,
NO_OF_OUTPUTTER_STREAMS
};

const char* outputterStreamStrings[] =
{
"STDOUT",
"STDERR",
"FILE REDIRECT",
};

#define MAX_BUFFERS_SIZE 1024

int main(int argc, char** argv)
{
   char fileName[MAX_BUFFERS_SIZE];

   int type = 0;
   int stream = 0;
   bool usingOutputFileName = false;
   std::ofstream outputFile;
   std::ostream* outputStream;
   CppUnit::Outputter* outputter = NULL;

   // checking the program's arguments
   strcpy(fileName, "");
   if (argc >= MAX_NO_OF_OUTPUTTER_ARGS)
   {
      strcpy(fileName, argv[OUTPUTTER_FILENAME_INDEX]);
      usingOutputFileName = true;
   }
   else
   {
      strcpy(fileName, argv[PROGRAM_NAME_INDEX]);
      strcat(fileName, ".txt");
   }

   if (argc > OUTPUTTER_STREAM_INDEX)
   {
      stream = atoi(argv[OUTPUTTER_STREAM_INDEX]);
   }

   if (argc > OUTPUTTER_TYPE_INDEX)
   {
      type = atoi(argv[OUTPUTTER_TYPE_INDEX]);
   }

  // Get the top level suite from the registry
   CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

   // Adds the test to the list of test to run
   CppUnit::TextUi::TestRunner runner;
   runner.addTest( suite );

   // set the output stream
   switch(stream)
   {
      case OUTPUTTER_STREAM_STDERR:
         outputStream = &std::cerr;
         break;
      case OUTPUTTER_STREAM_FILE_REDIRECT:
         // TODO : complete this later
         outputStream = &std::cout;
         usingOutputFileName = true;
         break;
      case OUTPUTTER_STREAM_STDOUT:
      default:
         outputStream = &std::cout;
         break;
   }

   // set the outputter type / default is compiler based
   switch(type)
   {
      case OUTPUTTER_TEXT_OUTPUT:
         outputter = new CppUnit::TextOutputter(&runner.result(),\
            *outputStream);
         break;
      case OUTPUTTER_XML_OUTPUT:
         outputter = new CppUnit::XmlOutputter(&runner.result(),\
            *outputStream);
         break;
      case OUTPUTTER_COMPILER_VCPLUSPLUS_OUTPUT:
         outputter = new CppUnit::CompilerOutputter(&runner.result(),\
            *outputStream,"%p(%l):");
         break;
      case OUTPUTTER_COMPILER_GCC_OUTPUT:
      default:
         outputter = new CppUnit::CompilerOutputter(&runner.result(),\
            *outputStream);
         break;
   }

   // writing header for debugging
   *outputStream
      << "OUTPUT TYPE - " << outputterTypeStrings[type]  << std::endl
      << "STREAM - "  << outputterStreamStrings[stream] << std::endl;

   if (usingOutputFileName)
   {
      *outputStream << "OUTPUT FILENAME - " << fileName << std::endl;
   }

   // Change the default outputter to a compiler error format outputter
   runner.setOutputter(outputter);
   // Run the tests.
   bool wasSucessful = runner.run();

   if (wasSucessful)
   {
      *outputStream  << "TEST SUITE SUCCESSFUL" << std::endl;
   }
   else
   {
      *outputStream  << "TEST SUITE FAILURE" << std::endl;
   }
   // Return error code 1 if the one of test failed.

   return wasSucessful ? 0 : 1;
}

