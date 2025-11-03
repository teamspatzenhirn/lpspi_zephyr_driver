# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_include_directories(.)
zephyr_library_sources_ifdef(CONFIG_SPI_MCUX_LPSPI spi_mcux_lpspi.c)
zephyr_library_sources_ifdef(CONFIG_SPI_MCUX_LPSPI fsl_lpspi.c)
