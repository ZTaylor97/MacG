namespace MacG
{
	enum class LayerType
	{
		FARBACKGROUND_LAYER,
		NEARBACKGROUND_LAYER,
		TILEMAP_LAYER,
		SCENERY_LAYER,
		ENTITYPARENT_LAYER, // eg Player, enemies, NPCs
		ENTITYCHILD_LAYER, // eg weapons, projectiles, status effects
		UI_LAYER
	};

	constexpr int NUM_LAYERS = (int)LayerType::UI_LAYER + 1;
}

