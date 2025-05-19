import os
import pathlib

def make_header(a_directory, a_filename, a_exclude = set()):
	a_exclude.add(a_filename)

	with open(a_directory + "/" + a_filename, "w", encoding="utf-8") as out:
		out.write("#pragma once\n")
		out.write("\n")
		out.write('#include "F4SE/Impl/PCH.h"\n')
		out.write("\n")

		tmp = []
		for dirpath, dirnames, filenames in os.walk(a_directory):
			rem = []
			for dirname in dirnames:
				if dirname in a_exclude:
					rem.append(dirname)
			for todo in rem:
				dirnames.remove(todo)

			for filename in filenames:
				if filename not in a_exclude and filename.endswith((".h", ".hpp", ".hxx")):
					path = os.path.join(dirpath, filename)
					tmp.append(os.path.normpath(path))

		files = []
		for file in tmp:
			files.append(file.replace("\\", "/"))

		files.sort()
		for file in files:
			out.write('#include "')
			out.write(file)
			out.write('"\n')

def main():
	root = pathlib.Path(os.path.dirname(os.path.realpath(__file__))).parent.parent
	os.chdir(os.path.join(root, "include"))

	make_header("F4SE", "F4SE.h", { "Impl" })
	make_header("RE", "Fallout.h", { "BSCoreTypes.h", "IDs.h", "IDs_NiRTTI.h", "IDs_RTTI.h", "IDs_VTABLE.h" })
	make_header("Scaleform", "Scaleform.h")

if __name__ == "__main__":
	main()
