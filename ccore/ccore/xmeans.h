/**************************************************************************************************************

Cluster analysis algorithm: X-Means

Based on article description:
 - D.Pelleg, A.Moore. X-means: Extending K-means with Efficient Estimation of the Number of Clusters. 2000.

Copyright (C) 2015    Andrei Novikov (spb.andr@yandex.ru)

pyclustering is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

pyclustering is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************************************************/

#ifndef _XMEANS_H_
#define _XMEANS_H_

#include <vector>

#define FAST_SOLUTION

class xmeans {
private:
	std::vector<std::vector<double> >			* dataset;
	std::vector<std::vector<unsigned int> *>	* clusters;
	std::vector<std::vector<double> >			* centers;

	unsigned int								maximum_clusters;
	double										tolerance;

public:
	xmeans(const std::vector<std::vector<double> > * const data, const std::vector<std::vector<double> > * const initial_centers, const unsigned int kmax, const double minimum_change);

	~xmeans(void);

	void process(void);

	inline const std::vector<std::vector<unsigned int> *> * const get_clusters(void) const {
		return clusters;
	}

private:
	void update_clusters(std::vector<std::vector<unsigned int> *> * clusters, std::vector<std::vector<double> > * centers, const std::vector<unsigned int> * const available_indexes);

	double update_centers(std::vector<std::vector<unsigned int> *> * clusters, std::vector<std::vector<double> > * centers);

	void improve_structure(void);

	void improve_parameters(std::vector<std::vector<unsigned int> *> * clusters, std::vector<std::vector<double> > * centers, const std::vector<unsigned int> * const available_indexes);

	double splitting_criterion(const std::vector<std::vector<unsigned int> * > * const clusters, const std::vector<std::vector<double> > * const centers) const;

	unsigned int find_proper_cluster(std::vector<std::vector<double> > * analysed_centers, const std::vector<double> * const point) const;
};

#endif