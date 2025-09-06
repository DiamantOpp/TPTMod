#include "simulation/ElementClasses.h"
#include "simulation/ElementCommon.h"
#include "simulation/ElementDefs.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_SURN()
{
	Identifier = "DEFAULT_PT_SURN";
	Name = "SURN";
	Colour = 0x707020_rgb;
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.95f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.4f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 12;
	PhotonReflectWavelengths = 0x003FC000;

	Weight = 130;

	DefaultProperties.temp = R_TEMP + 30.0f + 273.15f;
	HeatConduct = 251;
	Description = "Solid uranium. Heavy, generates heat under pressure.";

	Properties = TYPE_SOLID | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = 40;
	HighPressureTransition = PT_URAN;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (!sim->legacy_enable && sim->pv[y/CELL][x/CELL]>0.0f)
	{
		if (parts[i].temp == MIN_TEMP)
		{
			parts[i].temp += .01f;
		}
		else
		{
			parts[i].temp = restrict_flt((parts[i].temp*(1 + (sim->pv[y / CELL][x / CELL] / 2000))) + MIN_TEMP, MIN_TEMP, MAX_TEMP);
		}
	}
	return 0;
}
