#include "Misc.h"
#include "simulation/ElementClasses.h"
#include "simulation/ElementCommon.h"
#include "simulation/ElementDefs.h"
#include <linux/limits.h>

static int update(UPDATE_FUNC_ARGS);

void Element::Element_LID() {
	Identifier = "DEFAULT_PT_LID";
	Name = "LID";
	Colour = 0xF7FAFF_rgb;
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	Advection = 0.8f;
	AirDrag = 0.02f * CFDS;
	AirLoss = 0.97f;
	Loss = 0.80f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 31;

	DefaultProperties.temp = R_TEMP - 2.0f + 273.15f;
	HeatConduct = 251;
	Description = "Lithium deuteride. Reacts with neutrons and releases immense energy.";

	Properties = TYPE_PART|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	DefaultProperties.life = 10;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS) {
	Particle &self = parts[i];

	for (int rx = -1; rx <= 1; ++rx)
		for (int ry = -1; ry <= 1; ++ry) {
			if (!rx && !ry) continue;

			// Lithium reacts with water
			int neighborData = pmap[y + ry][x + rx];
			if (!neighborData)
				continue;

			auto typ = TYP(neighborData);

			if (
				typ != PT_SLTW // Salt water
			 && typ != PT_WTRV // Steam
			 && typ != PT_WATR // Water
			 && typ != PT_DSTW // Distilled water
			 && typ != PT_CBNW // Carbonated water
			) continue;
			
			if (self.temp > 440) {
				parts[sim->create_part(-1, x+rx, y+ry, PT_FIRE)].temp = 1000;
				parts[sim->create_part(sim->rng.chance(1, 4)? i : -1, x, y, PT_FIRE)].temp = 1000;
				break;
			}

			self.temp = restrict_flt(self.temp + 20.365f, MIN_TEMP, MAX_TEMP);
		}

	// Deuteride reactions
	// (MOVED, see src/simulation/elements/NEUT.cpp line 106)

	return 0;
}
