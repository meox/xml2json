#include <iostream>

#include "json.hpp"
#include "pugixml.hpp"

using json = nlohmann::json;

namespace xml2json
{
	json render_node(const pugi::xml_node& node)
	{
		std::string node_name;
		if (node.type() == pugi::node_document)
			node_name = "root";
		else
			node_name = node.name();

		json j = {
			{"node_name", node_name}
		};

		std::string value{};

		if (node.type() == pugi::node_element || node.type() == pugi::node_document)
		{
			bool found{false};
			auto ch = node.children();
			for (auto it = ch.begin(); it != ch.end(); ++it)
			{
				const auto type = it->type();

				if (type == pugi::node_element)
				{
					if (!found)
					{
						j["children"] = json::array();
						found = true;
					}

					json j_ch = render_node(*it);
					j["children"].push_back(j_ch);
				}
				else if (type == pugi::node_pcdata || type == pugi::node_cdata)
				{
					value += it->value();
				}
			}
		}

		j["value"] = value;

		bool found{false};
		auto attrs = node.attributes();
		for (auto it = attrs.begin(); it != attrs.end(); ++it)
		{
			if (!found)
			{
				j["attributes"] = json::array();
				found = true;
			}

			j["attributes"].push_back(json{
					{"name", it->name()},
					{"value", it->value()}
			});
		}
		return j;
	}


	std::string parseit(const std::string& f, int indent = -1)
	{
		pugi::xml_document doc;
		if (!doc.load_file(f.c_str()))
		{
			std::cerr << "is not possible to load " << f << std::endl;
			return "";
		}

		pugi::xml_node root = doc.root();
		json jroot = render_node(root);

		return jroot.dump(indent);
	}
}



int main(int argc, char* argv[])
{
	std::string fname;
	int indent = -1;

	if (argc == 1)
	{
		std::cout << argv[0] << " <filename> [indentation]";
		return 1;
	}
	else
	{
		fname = argv[1];
	}

	if (argc == 3)
		indent = std::stoi(argv[2]);

	std::cout << xml2json::parseit(fname, indent) << std::endl;
	return 0;
}