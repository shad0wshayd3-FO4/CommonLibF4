#pragma once

#include "Scaleform/G/GFx_FileTypeConstants.h"
#include "Scaleform/G/GFx_MemoryParams.h"
#include "Scaleform/G/GFx_Resource.h"
#include "Scaleform/G/GFx_StateBag.h"
#include "Scaleform/R/Render_Point.h"
#include "Scaleform/R/Render_Rect.h"

namespace Scaleform
{
	class MemoryHeap;

	namespace Render
	{
		class ThreadCommandQueue;
	}

	namespace GFx
	{
		class ActionControl;
		class ExporterInfo;
		class MemoryContext;
		class Movie;
		class ResourceId;

		class __declspec(novtable) MovieDef :
			public Resource,  // 00
			public StateBag   // 18
		{
		public:
			enum class FileAttrFlags : std::uint32_t
			{
				kUseNetwork = 1 << 0,
				kUseActionScript3 = 1 << 3,
				kHasMetadata = 1 << 4
			};

			enum class VisitResourceMask : std::uint32_t
			{
				kNestedMovies = 1 << 15,

				kFonts = 1 << 0,
				kBitmaps = 1 << 1,
				kGradientImages = 1 << 2,
				kEditTextFields = 1 << 3,
				kSounds = 1 << 4,
				kSprite = 1 << 5,

				kAllLocalImages = (kBitmaps | kGradientImages),
				kAllImages = (kBitmaps | kGradientImages | kNestedMovies)
			};

			class __declspec(novtable) ImportVisitor
			{
			public:
				virtual ~ImportVisitor() = default;  // 00

				// add
				virtual void Visit(MovieDef* a_parentDef, MovieDef* a_importDef, const char* a_importedMovieFilename) = 0;  // 01
			};
			static_assert(sizeof(ImportVisitor) == 0x8);

			class __declspec(novtable) ResourceVisitor :
				public FileTypeConstants  // 00
			{
			public:
				virtual ~ResourceVisitor() = default;  // 00

				// add
				virtual void Visit(MovieDef* a_movieDef, Resource* a_resource, ResourceId a_rid, const char* a_exportName) = 0;  // 01
			};
			static_assert(sizeof(ResourceVisitor) == 0x8);

			// add
			virtual std::uint32_t       GetVersion() const = 0;                                                                                                                                     // 04
			virtual std::uint32_t       GetLoadingFrame() const = 0;                                                                                                                                // 05
			virtual float               GetWidth() const = 0;                                                                                                                                       // 06
			virtual float               GetHeight() const = 0;                                                                                                                                      // 07
			virtual std::uint32_t       GetFrameCount() const = 0;                                                                                                                                  // 08
			virtual float               GetFrameRate() const = 0;                                                                                                                                   // 09
			virtual Render::Rect<float> GetFrameRect() const = 0;                                                                                                                                   // 0A
			virtual std::uint32_t       GetSWFFlags() const = 0;                                                                                                                                    // 0B
			virtual const char*         GetFileURL() const = 0;                                                                                                                                     // 0C
			virtual void                WaitForLoadFinish(bool a_cancel = false) const = 0;                                                                                                         // 0D
			virtual void                WaitForFrame(std::uint32_t a_frame) const = 0;                                                                                                              // 0E
			virtual FileAttrFlags       GetFileAttributes() const = 0;                                                                                                                              // 0F
			virtual std::uint32_t       GetMetadata(char* a_buff, std::uint32_t a_buffSize) const = 0;                                                                                              // 10
			virtual MemoryHeap*         GetLoadDataHeap() const = 0;                                                                                                                                // 11
			virtual MemoryHeap*         GetBindDataHeap() const = 0;                                                                                                                                // 12
			virtual MemoryHeap*         GetImageHeap() const = 0;                                                                                                                                   // 13
			virtual Resource*           GetMovieDataResource() const = 0;                                                                                                                           // 14
			virtual const ExporterInfo* GetExporterInfo() const = 0;                                                                                                                                // 15
			virtual MemoryContext*      CreateMemoryContext(const char* a_heapName, const MemoryParams& a_memParams, bool a_debugHeap) = 0;                                                         // 16
			virtual Movie*              CreateInstance(const MemoryParams& a_memParams, bool a_initFirstFrame, ActionControl* a_actionControl, Render::ThreadCommandQueue* a_queue = nullptr) = 0;  // 18
			virtual Movie*              CreateInstance(MemoryContext* a_memContext, bool a_initFirstFrame, ActionControl* a_actionControl, Render::ThreadCommandQueue* a_queue = nullptr) = 0;      // 17
			virtual void                VisitImportedMovies(ImportVisitor* a_visitor) = 0;                                                                                                          // 19
			virtual void                VisitResources(ResourceVisitor* a_visitor, VisitResourceMask a_visitMask = VisitResourceMask::kAllImages) = 0;                                              // 1A
			virtual Resource*           GetResource(const char* a_exportName) const = 0;                                                                                                            // 1B

			[[nodiscard]] Movie* CreateInstance(
				bool                        a_initFirstFrame = false,
				std::size_t                 a_memoryArena = 0,
				ActionControl*              a_actionControl = nullptr,
				Render::ThreadCommandQueue* a_queue = nullptr)
			{
				MemoryParams memParams;
				memParams.desc.arena = a_memoryArena;
				return CreateInstance(memParams, a_initFirstFrame, a_actionControl, a_queue);
			}
		};
		static_assert(sizeof(MovieDef) == 0x20);
	}
}
