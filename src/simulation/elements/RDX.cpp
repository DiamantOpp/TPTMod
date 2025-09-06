#include "simulation/ElementCommon.h"

void Element::Element_RDX()
{
	Identifier = "DEFAULT_PT_RDX";
	Name = "RDX";
	Colour = 0xB0D0E0_rgb;
	MenuVisible = 1;
	MenuSection = SC_EXPLOSIVE;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 1500;
	Explosive = 2;
	Meltable = 80;
	Hardness = 10;
	PhotonReflectWavelengths = 0x1F00003E;

	Weight = 150;

	HeatConduct = 88;
	Description = "Cyclonite. A powerful crystalline explosive.";

	Properties = TYPE_SOLID | PROP_NEUTPENETRATE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 523.0f;
	HighTemperatureTransition = PT_FIRE;
}
