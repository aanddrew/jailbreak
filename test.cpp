
int loadBases(string[] bases, string playerName, int sizeHit)
{
	int pointsScored = 0;
	int i = 0;
	while (i < sizeHit)
	{
		string tempPlayer = bases[3];
		for (int i = 2; i >= 0; i--)
		{
			//replaces the player at next index with current index
			bases[i] = bases[i+1];
		}
	}

	return pointsScored;
}

string bases[4];