/*
 *  Setup code for AT91SAM Evaluation Kits with Device Tree support
 *
 *  Copyright (C) 2011 Atmel,
 *                2011 Nicolas Ferre <nicolas.ferre@atmel.com>
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>

#include <asm/setup.h>
#include <asm/irq.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach/irq.h>

#include "at91_aic.h"
#include "board.h"
#include "generic.h"

/************************************/
/* TEMPORARY NON-DT STUFF LCD       */
/************************************/
#include <linux/fb.h>
#include <video/atmel_lcdfb.h>
#include <mach/atmel_hlcdc.h>
#include <mach/atmel_lcdc.h>

/*
 * LCD Controller
 */
static struct fb_videomode at91_tft_vga_modes[] = {
	{
		.name		= "LG",
		.refresh	= 60,
		.xres		= 800,		.yres		= 480,
		.pixclock	= KHZ2PICOS(33260),

		.left_margin	= 88,		.right_margin	= 168,
		.upper_margin	= 8,		.lower_margin	= 37,
		.hsync_len	= 128,		.vsync_len	= 2,

		.sync		= 0,
		.vmode		= FB_VMODE_NONINTERLACED,
	},
};

static struct fb_monspecs at91fb_default_monspecs = {
	.manufacturer	= "LG",
	.monitor	= "LB043WQ1",

	.modedb		= at91_tft_vga_modes,
	.modedb_len	= ARRAY_SIZE(at91_tft_vga_modes),
	.hfmin		= 15000,
	.hfmax		= 17640,
	.vfmin		= 57,
	.vfmax		= 67,
};

/* Default output mode is TFT 24 bit */
#define BPP_OUT_DEFAULT_LCDCFG5	(LCDC_LCDCFG5_MODE_OUTPUT_24BPP)

/* Driver datas */
static struct atmel_lcdfb_info __initdata ek_lcdc_data = {
	.lcdcon_is_backlight		= true,
	.alpha_enabled			= false,
	.default_bpp			= 16,
	/* Reserve enough memory for 32bpp */
	.smem_len			= 800 * 480 * 4,
	/* default_lcdcon2 is used for LCDCFG5 */
	.default_lcdcon2		= BPP_OUT_DEFAULT_LCDCFG5,
	.default_monspecs		= &at91fb_default_monspecs,
	.guard_time			= 9,
	.lcd_wiring_mode		= ATMEL_LCDC_WIRING_RGB,
};

struct of_dev_auxdata at91_auxdata_lookup[] __initdata = {
	OF_DEV_AUXDATA("atmel,at91sam9x5-lcd", 0xf8038000, "atmel_hlcdfb_base", &ek_lcdc_data),
	OF_DEV_AUXDATA("atmel,at91sam9x5-lcd", 0xf8038100, "atmel_hlcdfb_ovl1", &ek_lcdc_data),
	OF_DEV_AUXDATA("atmel,at91sam9g45-lcd", 0x00500000, "atmel_lcdfb", &ek_lcdc_data),
	{ /* sentinel */ }
};

static const struct of_device_id irq_of_match[] __initconst = {

	{ .compatible = "atmel,at91rm9200-aic", .data = at91_aic_of_init },
	{ /*sentinel*/ }
};

static void __init at91_dt_init_irq(void)
{
	of_irq_init(irq_of_match);
}

static void __init at91_dt_device_init(void)
{
	if (of_machine_is_compatible("atmel,at91sam9n12ek")) {
		__u8 manufacturer[4] = "QD";
		__u8 monitor[14] = "QD43003C1";

		/* set LCD configuration */
		at91_tft_vga_modes[0].name = "QD";
		at91_tft_vga_modes[0].xres = 480;
		at91_tft_vga_modes[0].yres = 272;
		at91_tft_vga_modes[0].pixclock = KHZ2PICOS(9000),

		at91_tft_vga_modes[0].left_margin = 8;
		at91_tft_vga_modes[0].right_margin = 43;
		at91_tft_vga_modes[0].upper_margin = 4;
		at91_tft_vga_modes[0].lower_margin = 12;
		at91_tft_vga_modes[0].hsync_len = 5;
		at91_tft_vga_modes[0].vsync_len = 10;

		memcpy(at91fb_default_monspecs.manufacturer, manufacturer, 4);
		memcpy(at91fb_default_monspecs.monitor, monitor, 14);

		printk("LCD parameters updated for at91sam9n12ek display module\n");
	}

	if (of_machine_is_compatible("atmel,at91sam9m10g45ek")) {
		#define AT91SAM9G45_DEFAULT_LCDCON2		\
				(ATMEL_LCDC_MEMOR_LITTLE \
				 | ATMEL_LCDC_DISTYPE_TFT \
				 | ATMEL_LCDC_CLKMOD_ALWAYSACTIVE)

		/* set LCD configuration */
		at91_tft_vga_modes[0].xres = 480;
		at91_tft_vga_modes[0].yres = 272;
		at91_tft_vga_modes[0].pixclock = KHZ2PICOS(9000),

		at91_tft_vga_modes[0].left_margin = 1;
		at91_tft_vga_modes[0].right_margin = 1;
		at91_tft_vga_modes[0].upper_margin = 40;
		at91_tft_vga_modes[0].lower_margin = 1;
		at91_tft_vga_modes[0].hsync_len = 45;
		at91_tft_vga_modes[0].vsync_len = 1;

		ek_lcdc_data.default_lcdcon2 = AT91SAM9G45_DEFAULT_LCDCON2;
		ek_lcdc_data.default_dmacon = ATMEL_LCDC_DMAEN;

		printk("LCD parameters updated for at91sam9m10g45ek display module\n");
	}

	of_platform_populate(NULL, of_default_bus_match_table, at91_auxdata_lookup, NULL);
}

static const char *at91_dt_board_compat[] __initdata = {
	"atmel,at91sam9",
	NULL
};

DT_MACHINE_START(at91sam_dt, "Atmel AT91SAM (Device Tree)")
	/* Maintainer: Atmel */
	.init_time	= at91sam926x_pit_init,
	.map_io		= at91_map_io,
	.handle_irq	= at91_aic_handle_irq,
	.init_early	= at91_dt_initialize,
	.init_irq	= at91_dt_init_irq,
	.init_machine	= at91_dt_device_init,
	.dt_compat	= at91_dt_board_compat,
MACHINE_END
