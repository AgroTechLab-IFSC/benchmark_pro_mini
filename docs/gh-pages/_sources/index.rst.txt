.. Benchmark Arduino Pro Mini documentation master file, created by
   sphinx-quickstart on Sun Jan  5 08:22:54 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Benchmark Arduino Pro Mini
==========================

**Benchmark for Arduino Pro Mini** is a IoT tool developed by `AgroTechLab <https://agrotechlab.lages.ifsc.edu.br>`_ (*Technology Development 
Laboratory for Agribusiness*) of `IFSC <https://www.ifsc.edu.br>`_ (*Federal Institute of Santa Catarina*).

It aims to get data about the energy consumption of Arduino Pro Mini in different operation modes. It can be used in conjunction 
with a power consumption analysis tool such as `Power Monitor <https://github.com/AgroTechLab-IFSC/power_monitor>`_.

The following modes are provided in order to test energy consumption:

   - **BENCHMARK_MODE_0**
      - Duty cycle: 100%
      - Default arduino project configuration;
      - Builtin LED on;
      - loop process empty;
   - **BENCHMARK_MODE_1**
      - Duty cycle: 100%
      - Default arduino project configuration;
      - Builtin LED on;
      - add, sub, mult, div operations (1000 times);
      - toggle all digital I/O ports;
      - read all analogic input ports;
      - UART (serial) communication at 115200 baudrate (5 bytes);
   - **BENCHMARK_MODE_2**
      - Duty cycle: 100%
      - Only 3 digital I/O are set to OUTPUT the rest are set to INPUT_PULLUP;
      - All analogic port are set to LOW; 
      - Builtin LED off;
      - add, sub, mult, div operations (1000 times);
      - toggle 3 digital I/O ports;    
      - UART (serial) communication at 115200 baudrate (5 bytes);
      - disable ADC;
      - disable SPI;
   - **BENCHMARK_MODE_3**
      - BENCHMARK_MODE_2
      - CPU clock is reduced to 50% (8MHz);
   - **BENCHMARK_MODE_4**
      - BENCHMARK_MODE_3
      - CPU clock is reduced to 25% (4MHz);

Versions support
----------------

Updates and new features are constantly being added to **Benchmark for Arduino Pro Mini**. The following table shows the supported versions:

.. table::
   :align: center
   :widths: 20 20 20   

   +---------+------------+--------------+
   | Version |  Security  | New features |
   +=========+============+==============+
   |  0.x.x  |     Yes    |     Yes      |
   +---------+------------+--------------+

.. toctree::
   :name: mastertoc
   :maxdepth: 2
   :caption: Table of Contents:

   authors_license
   changelog
   hw_req
   source_code_docs

