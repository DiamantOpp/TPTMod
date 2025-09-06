#include "simulation/ElementCommon.h"
#include "simulation/ElementDefs.h"

void Element::Element_HLUM()
{
	Identifier = "DEFAULT_PT_HLUM";
	Name = "HLUM";
	Colour = 0x90B0FF_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 0.9f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.25f;
	Collision = 0.0f;
	Gravity = -1.45f;
	Diffusion = 0.75f;
	HotAir = 0.0005f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 1;
	PhotonReflectWavelengths = 0xFFFFFFFF;

	Weight = 1;

	DefaultProperties.temp = 6.0f + 273.15f;
	HeatConduct = 106;
	Description = "Helium. Much lighter than air.";

	Properties = TYPE_GAS|PROP_NEUTPASS|PROP_LIFE_DEC|PROP_LIFE_KILL;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

    DefaultProperties.life = 3600; // One minute
}
